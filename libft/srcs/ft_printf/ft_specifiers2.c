/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:49:04 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 19:56:18 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_specifier_c(t_info *info, t_format *format, char c)
{
	int		num;
	char	tmp[2];

	num = va_arg((*info).ap, int);
	if ((*format).lmod != NULL || c == 'C')
		(*format).value_str = ft_get_wchar(num);
	else
	{
		tmp[0] = (char)num;
		tmp[1] = '\0';
		(*format).value_str = ft_strdup(tmp);
	}
	return (TRUE);
}

int		ft_specifier_s(t_info *info, t_format *format, char c)
{
	char	*s;

	s = va_arg((*info).ap, char *);
	if (s == NULL)
	{
		(*format).value_str = ft_strdup("(null)");
		return (TRUE);
	}
	if ((*format).lmod != NULL || c == 'S')
		(*format).value_str = ft_get_wstring((int *)s);
	else
		(*format).value_str = ft_strdup(s);
	return (TRUE);
}

int		ft_specifier_p(t_info *info, t_format *format)
{
	long	*num;

	num = va_arg((*info).ap, long *);
	if (num == NULL)
	{
		(*format).value_str = ft_strdup("0");
		(*format).flag_sharp = 1;
	}
	else
	{
		(*format).value_str =
		ft_itoa_base((unsigned long)num, "0123456789abcdef");
		(*format).flag_sharp = 1;
	}
	return (TRUE);
}

int		ft_specifier_invalid(t_format *format, char c)
{
	char	tmp[2];

	if (c == '\0')
	{
		(*format).value_str = ft_strdup("");
		return (TRUE);
	}
	tmp[0] = c;
	tmp[1] = '\0';
	(*format).value_str = ft_strdup(tmp);
	return (TRUE);
}
