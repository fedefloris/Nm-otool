/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:21:54 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 15:59:41 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		set_width_param(t_fmt_ops *ops)
{
	ops->width = va_arg(*(ops->tp->params), int);
	ops->tp->index++;
	if (ops->width < 0)
	{
		ops->left = 1;
		ops->width = -ops->width;
	}
}

void		set_width_nbr(t_fmt_ops *ops)
{
	int	n;

	n = 0;
	while (ft_isdigit(ops->tp->s[ops->tp->index + n]))
		n++;
	if (n > 0)
	{
		ops->width = ft_atoi_n(ops->tp->s + ops->tp->index, n);
		ops->tp->index += n;
	}
}

void		set_width(t_fmt_ops *ops)
{
	set_width_nbr(ops);
	if (!ft_strncmp(ops->tp->s + ops->tp->index, WIDTH_PARAM, 1))
	{
		set_width_param(ops);
		set_width_nbr(ops);
	}
	if (ops->width == 0)
		ops->width = -1;
	else if (ops->width < 0)
		ops->width = 0;
}
