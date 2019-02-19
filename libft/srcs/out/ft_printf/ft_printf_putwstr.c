/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putwstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:10:37 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 13:12:28 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putwstr(t_fmt_ops *ops, wchar_t *s, intmax_t s_size)
{
	if (ops->left)
		ft_putnwstr_fd(s, ops->tp->fd, s_size);
	if (ops->width)
		add_padding(ops, s_size);
	if (!ops->left)
		ft_putnwstr_fd(s, ops->tp->fd, s_size);
}

void		ft_printf_putwstr(t_fmt_ops *ops)
{
	wchar_t		*s;
	intmax_t	temp;
	intmax_t	s_size;

	if (!(s = va_arg(*(ops->tp->params), wchar_t*)))
		s = L"(null)";
	s_size = ft_wstrblen(s);
	temp = ops->precision;
	if (temp != 0 && s_size > temp)
		s_size = temp;
	if (s_size == -1)
		s_size = 0;
	s_size = ft_nwstrblen(s, (size_t)s_size);
	putwstr(ops, s, s_size);
	ops->tp->chrs_written += s_size;
}
