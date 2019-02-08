/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putonbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:43:51 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 09:51:55 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putprefix(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (ops->convert && nbr_ops->nbr != 0)
		ft_putchar_fd('0', ops->tp->fd);
}

static void	putonbr_no_prec(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (ops->left)
	{
		putprefix(ops, nbr_ops);
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 8, 0);
		padding_with(ops, nbr_ops->nbr_size, ' ');
	}
	else if (ops->zeros && ops->precision != -1)
	{
		putprefix(ops, nbr_ops);
		padding_with(ops, nbr_ops->nbr_size, '0');
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 8, 0);
	}
	else
	{
		padding_with(ops, nbr_ops->nbr_size, ' ');
		putprefix(ops, nbr_ops);
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 8, 0);
	}
}

static void	putonbr_prec(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	int		off;

	off = ops->precision - nbr_ops->nbr_size;
	if (ops->convert && nbr_ops->nbr != 0)
		off++;
	off = ft_clamp(off, 0, off);
	if (!ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
	putprefix(ops, nbr_ops);
	padding_with_prec(ops, nbr_ops->nbr_size, '0');
	ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 8, 0);
	if (ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
}

static void	putonbr(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (ops->convert && nbr_ops->nbr != 0)
		nbr_ops->nbr_size++;
	if (ops->precision > 0)
		putonbr_prec(ops, nbr_ops);
	else
		putonbr_no_prec(ops, nbr_ops);
	ops->tp->chrs_written += nbr_ops->nbr_size;
}

void		ft_printf_putonbr(t_fmt_ops *ops)
{
	t_nbr		nbr_ops;

	nbr_ops.nbr = ft_printf_get_unbr(ops);
	nbr_ops.nbr_size = ft_printf_get_unbr_length(nbr_ops.nbr, 8);
	if (!nbr_ops.nbr && ops->precision == -1)
	{
		if (ops->convert)
		{
			ft_putchar_fd('0', ops->tp->fd);
			ops->tp->chrs_written++;
		}
		padding_with(ops, ops->convert, ' ');
	}
	else
		putonbr(ops, &nbr_ops);
}
