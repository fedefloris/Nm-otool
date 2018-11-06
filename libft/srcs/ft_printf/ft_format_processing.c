/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:40:27 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 20:42:17 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_specifier_value(t_info *info, t_format *format, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_specifier_di(info, format));
	else if (c == 'u')
		return (ft_specifier_u(info, format));
	else if (c == 'o' || c == 'x' || c == 'X')
		return (ft_specifier_ox(info, format, c));
	else if (c == 'D' || c == 'U' || c == 'O')
		return (ft_specifier_cap_duo(info, format, c));
	else if (c == 'c' || c == 'C')
		return (ft_specifier_c(info, format, c));
	else if (c == 's' || c == 'S')
		return (ft_specifier_s(info, format, c));
	else if (c == 'p')
		return (ft_specifier_p(info, format));
	else if (c == '%')
		return (ft_specifier_percent(format));
	else
		return (ft_specifier_invalid(format, c));
}

static int	ft_apply_format(t_info *info, t_format *format, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (ft_format_di(info, format));
	else if (c == 'o' || c == 'O')
		return (ft_format_o(info, format));
	else if (c == 'x')
		return (ft_format_x(info, format, c));
	else if (c == 'X')
		return (ft_format_x(info, format, c));
	else if (c == 'u' || c == 'U')
		return (ft_format_u(info, format));
	else if (c == 'c' || c == 'C')
		return (ft_format_c(info, format));
	else if (c == 's' || c == 'S')
		return (ft_format_s(info, format));
	else if (c == 'p')
		return (ft_format_p(info, format));
	else if (c == '%')
		return (ft_format_percent(info, format));
	else
		return (ft_format_invalid_specifier(info, format));
}

int			ft_format_processing(t_info *info, t_format *format, char c)
{
	if (ft_get_specifier_value(info, format, c) == FALSE)
		return (FALSE);
	if (ft_apply_format(info, format, c) == FALSE)
		return (FALSE);
	return (TRUE);
}
