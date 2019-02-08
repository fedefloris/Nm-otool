/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:43:35 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/25 12:23:25 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

uintmax_t		ft_printf_get_unbr_length(uintmax_t nbr, uintmax_t base)
{
	uintmax_t	length;

	length = 1;
	while ((nbr /= base) > 0)
		length++;
	return (length);
}

static intmax_t	get_nbr(t_fmt_ops *ops)
{
	if (!ft_strncmp(ops->type, TYPE_LONG_INT, 1) ||
		ops->long_type == 1)
		return (va_arg(*(ops->tp->params), long));
	else if (ops->long_type == 2)
		return (va_arg(*(ops->tp->params), long long));
	else if (ops->short_type == 1)
		return ((short)va_arg(*(ops->tp->params), int));
	else if (ops->short_type == 2)
		return ((char)va_arg(*(ops->tp->params), int));
	else if (ops->intmax_type)
		return (va_arg(*(ops->tp->params), intmax_t));
	else if (ops->size_t_type)
		return (va_arg(*(ops->tp->params), ssize_t));
	return (va_arg(*(ops->tp->params), int));
}

uintmax_t		ft_printf_get_nbr(t_fmt_ops *ops, int *neg)
{
	intmax_t		nbr;
	uintmax_t		unbr;

	nbr = get_nbr(ops);
	if (nbr < 0)
	{
		*neg = 1;
		nbr = -nbr;
	}
	unbr = nbr;
	return (unbr);
}

uintmax_t		ft_printf_get_unbr(t_fmt_ops *ops)
{
	if (ops->long_type == 1 ||
		!ft_strncmp(ops->type, TYPE_LONG_DECIMAL, 1) ||
		!ft_strncmp(ops->type, TYPE_LONG_OCTAL, 1))
		return (va_arg(*(ops->tp->params), unsigned long));
	else if (ops->long_type == 2)
		return (va_arg(*(ops->tp->params), unsigned long long));
	else if (ops->short_type == 1)
		return ((unsigned short)va_arg(*(ops->tp->params), unsigned int));
	else if (ops->short_type == 2)
		return ((unsigned char)va_arg(*(ops->tp->params), unsigned int));
	else if (ops->intmax_type)
		return (va_arg(*(ops->tp->params), uintmax_t));
	else if (ops->size_t_type)
		return (va_arg(*(ops->tp->params), size_t));
	else
		return (va_arg(*(ops->tp->params), unsigned int));
}

void			ft_printf_put_uintmax_nbr(uintmax_t n, int fd, uintmax_t base,
														int hexa_uppercase)
{
	uintmax_t		nbr;
	char			off;

	if (n >= base)
		ft_printf_put_uintmax_nbr(n / base, fd, base, hexa_uppercase);
	nbr = n % base;
	off = '0';
	if (base > 9 && nbr > 9)
		off = (hexa_uppercase) ? '7' : 'W';
	ft_putchar_fd(nbr + off, fd);
}
