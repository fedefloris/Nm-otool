/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:28:36 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 19:48:15 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_specifier_di(t_info *info, t_format *format)
{
	long	num;

	if ((*format).lmod != NULL)
	{
		if (ft_isvalid_lmod(format) == FALSE)
			return (FALSE);
		if (ft_strcmp((*format).lmod, "hh") == 0)
			num = (char)va_arg((*info).ap, int);
		else if (ft_strcmp((*format).lmod, "h") == 0)
			num = (short)va_arg((*info).ap, int);
		else
			num = va_arg((*info).ap, long);
	}
	else
		num = va_arg((*info).ap, int);
	if (num == 0)
		(*format).is_zero = 1;
	(*format).value_str = ft_itoa_base_signed(num, "0123456789");
	if ((*format).value_str[0] == '-')
		(*format).neg_sign = 1;
	return (TRUE);
}

int		ft_specifier_u(t_info *info, t_format *format)
{
	unsigned long	num;

	if ((*format).lmod != NULL)
	{
		if (ft_isvalid_lmod(format) == FALSE)
			return (FALSE);
		if (ft_strcmp((*format).lmod, "hh") == 0)
			num = (unsigned char)va_arg((*info).ap, int);
		else if (ft_strcmp((*format).lmod, "h") == 0)
			num = (unsigned short)va_arg((*info).ap, int);
		else
			num = va_arg((*info).ap, long);
	}
	else
		num = va_arg((*info).ap, unsigned int);
	if (num == 0)
		(*format).is_zero = 1;
	(*format).value_str = ft_itoa_base(num, "0123456789");
	return (TRUE);
}

int		ft_specifier_ox(t_info *info, t_format *format, char c)
{
	unsigned long	num;

	if ((*format).lmod != NULL)
	{
		if (ft_isvalid_lmod(format) == FALSE)
			return (FALSE);
		if (ft_strcmp((*format).lmod, "hh") == 0)
			num = (unsigned char)va_arg((*info).ap, int);
		else if (ft_strcmp((*format).lmod, "h") == 0)
			num = (unsigned short)va_arg((*info).ap, int);
		else
			num = va_arg((*info).ap, long);
	}
	else
		num = va_arg((*info).ap, unsigned int);
	if (num == 0)
		(*format).is_zero = 1;
	if (c == 'o')
		(*format).value_str = ft_itoa_base(num, "01234567");
	else if (c == 'x')
		(*format).value_str = ft_itoa_base(num, "0123456789abcdef");
	else
		(*format).value_str = ft_itoa_base(num, "0123456789ABCDEF");
	return (TRUE);
}

int		ft_specifier_cap_duo(t_info *info, t_format *format, char c)
{
	long	num;

	num = va_arg((*info).ap, long);
	if (num == 0)
		(*format).is_zero = 1;
	if (c == 'D')
	{
		(*format).value_str = ft_itoa_base_signed(num, "0123456789");
		if ((*format).value_str[0] == '-')
			(*format).neg_sign = 1;
	}
	else if (c == 'U')
		(*format).value_str = ft_itoa_base(num, "0123456789");
	else
		(*format).value_str = ft_itoa_base(num, "01234567");
	return (TRUE);
}

int		ft_specifier_percent(t_format *format)
{
	char	tmp[2];

	tmp[0] = '%';
	tmp[1] = '\0';
	(*format).value_str = ft_strdup(tmp);
	return (TRUE);
}
