/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putbinary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:02:30 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 11:20:57 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putbinary_no_prec(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (ops->left)
	{
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 2, 0);
		padding_with(ops, nbr_ops->nbr_size, ' ');
	}
	else if (ops->zeros && ops->precision != -1)
	{
		padding_with(ops, nbr_ops->nbr_size, '0');
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 2, 0);
	}
	else
	{
		padding_with(ops, nbr_ops->nbr_size, ' ');
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 2, 0);
	}
}

static void	putbinary_prec(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	int		off;

	off = ops->precision - nbr_ops->nbr_size;
	off = ft_clamp(off, 0, off);
	if (!ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
	padding_with_prec(ops, nbr_ops->nbr_size, '0');
	ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 2, 0);
	if (ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
}

static void	putbinary(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (ops->precision > 0)
		putbinary_prec(ops, nbr_ops);
	else
		putbinary_no_prec(ops, nbr_ops);
	ops->tp->chrs_written += nbr_ops->nbr_size;
}

void		ft_printf_putbinary(t_fmt_ops *ops)
{
	t_nbr		nbr_ops;

	nbr_ops.nbr = ft_printf_get_unbr(ops);
	nbr_ops.nbr_size = ft_printf_get_unbr_length(nbr_ops.nbr, 2);
	if (!nbr_ops.nbr && ops->precision == -1)
		padding_with(ops, 0, ' ');
	else
		putbinary(ops, &nbr_ops);
}
