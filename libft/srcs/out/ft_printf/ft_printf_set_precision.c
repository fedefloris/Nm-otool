/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:22:29 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 15:56:03 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		set_prec_param(t_fmt_ops *ops)
{
	ops->precision = va_arg(*(ops->tp->params), int);
	ops->tp->index++;
}

void		set_prec_nbr(t_fmt_ops *ops)
{
	int	n;

	n = 0;
	while (ft_isdigit(ops->tp->s[ops->tp->index + n]))
		n++;
	if (n > 0)
	{
		ops->precision = ft_atoi_n(ops->tp->s + ops->tp->index, n);
		ops->tp->index += n;
	}
}

void		set_precision(t_fmt_ops *ops)
{
	if (!ft_strncmp(ops->tp->s + ops->tp->index, PRECISION_NUMBER, 1))
	{
		ops->tp->index++;
		set_prec_nbr(ops);
		if (!ft_strncmp(ops->tp->s + ops->tp->index, PRECISION_PARAM, 1))
		{
			set_prec_param(ops);
			set_prec_nbr(ops);
		}
		if (ops->precision == 0)
			ops->precision = -1;
		else if (ops->precision < 0)
			ops->precision = 0;
	}
}
