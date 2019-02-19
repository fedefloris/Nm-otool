/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putaddr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:34:12 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 09:51:36 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putprefix(t_fmt_ops *ops)
{
	ft_putchar_fd('0', ops->tp->fd);
	ft_putchar_fd('x', ops->tp->fd);
}

static void	putaddr_no_prec(t_fmt_ops *ops, uintptr_t ptr, uintmax_t nbr_size)
{
	if (ops->left)
	{
		putprefix(ops);
		ft_printf_put_uintmax_nbr(ptr, ops->tp->fd, 16, 0);
		padding_with(ops, nbr_size, ' ');
	}
	else if (ops->zeros && ops->precision != -1)
	{
		putprefix(ops);
		padding_with(ops, nbr_size, '0');
		ft_printf_put_uintmax_nbr(ptr, ops->tp->fd, 16, 0);
	}
	else
	{
		padding_with(ops, nbr_size, ' ');
		putprefix(ops);
		ft_printf_put_uintmax_nbr(ptr, ops->tp->fd, 16, 0);
	}
}

static void	putaddr_prec(t_fmt_ops *ops, uintptr_t ptr, uintmax_t nbr_size)
{
	int		off;

	off = ops->precision - nbr_size;
	off = ft_clamp(off, 0, off);
	if (!ops->left && ops->width)
		padding_with(ops, nbr_size + off, ' ');
	putprefix(ops);
	nbr_size -= 2;
	padding_with_prec(ops, nbr_size, '0');
	nbr_size += 2;
	ft_printf_put_uintmax_nbr(ptr, ops->tp->fd, 16, 0);
	if (ops->left && ops->width)
		padding_with(ops, nbr_size + off, ' ');
}

static void	putaddr(t_fmt_ops *ops, uintptr_t ptr, uintmax_t ptr_size)
{
	if (ops->precision > 0)
		putaddr_prec(ops, ptr, ptr_size);
	else
		putaddr_no_prec(ops, ptr, ptr_size);
	ops->tp->chrs_written += ptr_size;
}

void		ft_printf_putaddr(t_fmt_ops *ops)
{
	uintptr_t	ptr;
	uintmax_t	ptr_size;

	ptr = (uintptr_t)va_arg(*(ops->tp->params), void*);
	ptr_size = ft_printf_get_unbr_length((uintmax_t)ptr, 16) + 2;
	if (!ptr && ops->precision == -1)
	{
		putprefix(ops);
		ops->tp->chrs_written += 2;
		padding_with(ops, 2, ' ');
	}
	else
		putaddr(ops, ptr, ptr_size);
}
