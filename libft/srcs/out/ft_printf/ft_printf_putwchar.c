/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putwchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:13:01 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 14:28:43 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printf_putwchar(t_fmt_ops *ops)
{
	wchar_t	c;
	size_t	c_size;

	c = (wchar_t)va_arg(*(ops->tp->params), wint_t);
	c_size = ft_wcharlen(c);
	if (ops->left)
		ft_putwchar_fd(c, ops->tp->fd);
	if (ops->width)
		add_padding(ops, c_size);
	if (!ops->left)
		ft_putwchar_fd(c, ops->tp->fd);
	ops->tp->chrs_written += c_size;
	if (!c_size)
		ops->tp->exit = -1;
}
