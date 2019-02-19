/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:18:48 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 11:26:32 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putstr(t_fmt_ops *ops, char *s, intmax_t s_size)
{
	if (ops->left)
		ft_putnstr_fd((s) ? s : "(null)", ops->tp->fd, s_size);
	if (ops->width)
		add_padding(ops, s_size);
	if (!ops->left)
		ft_putnstr_fd((s) ? s : "(null)", ops->tp->fd, s_size);
	ops->tp->chrs_written += s_size;
}

void		ft_printf_putstr(t_fmt_ops *ops)
{
	char		*s;
	intmax_t	temp;
	intmax_t	s_size;

	if (ops->long_type)
	{
		ft_printf_putwstr(ops);
		return ;
	}
	if ((s = va_arg(*(ops->tp->params), char*)))
		s_size = ft_strlen(s);
	else
		s_size = 6;
	temp = ops->precision;
	if (temp != 0 && s_size > temp)
		s_size = temp;
	if (s_size == -1)
		s_size = 0;
	putstr(ops, s, s_size);
}
