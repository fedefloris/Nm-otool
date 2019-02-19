/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:45:47 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/25 10:21:15 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printf_putchar(t_fmt_ops *ops)
{
	char	c;

	if (ops->long_type)
	{
		ft_printf_putwchar(ops);
		return ;
	}
	c = (t_uchar)va_arg(*(ops->tp->params), int);
	if (ops->left)
		ft_putchar_fd(c, ops->tp->fd);
	if (ops->width)
		add_padding(ops, 1);
	if (!ops->left)
		ft_putchar_fd(c, ops->tp->fd);
	ops->tp->chrs_written++;
}
