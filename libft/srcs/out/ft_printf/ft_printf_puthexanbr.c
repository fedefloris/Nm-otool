/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthexanbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:44:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/25 17:14:51 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putprefix(t_fmt_ops *ops, t_nbr *nbr_ops, int upper)
{
	if (ops->convert && nbr_ops->nbr != 0)
	{
		ft_putchar_fd('0', ops->tp->fd);
		ft_putchar_fd((!upper) ? 'x' : 'X', ops->tp->fd);
	}
}

static void	puthexanbr_no_prec(t_fmt_ops *ops, t_nbr *nbr_ops, int upper)
{
	if (ops->left)
	{
		putprefix(ops, nbr_ops, upper);
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 16, upper);
		padding_with(ops, nbr_ops->nbr_size, ' ');
	}
	else if (ops->zeros && ops->precision != -1)
	{
		putprefix(ops, nbr_ops, upper);
		padding_with(ops, nbr_ops->nbr_size, '0');
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 16, upper);
	}
	else
	{
		padding_with(ops, nbr_ops->nbr_size, ' ');
		putprefix(ops, nbr_ops, upper);
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 16, upper);
	}
}

static void	puthexanbr_prec(t_fmt_ops *ops, t_nbr *nbr_ops, int upper)
{
	int		off;

	off = ops->precision - nbr_ops->nbr_size;
	if (ops->convert && nbr_ops->nbr != 0)
		off += 2;
	off = ft_clamp(off, 0, off);
	if (!ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
	putprefix(ops, nbr_ops, upper);
	if (ops->convert && nbr_ops->nbr != 0)
		nbr_ops->nbr_size -= 2;
	padding_with_prec(ops, nbr_ops->nbr_size, '0');
	if (ops->convert && nbr_ops->nbr != 0)
		nbr_ops->nbr_size += 2;
	ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 16, upper);
	if (ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
}

static void	puthexanbr(t_fmt_ops *ops, t_nbr *nbr_ops, int upper)
{
	if (ops->convert && nbr_ops->nbr != 0)
		nbr_ops->nbr_size += 2;
	if (ops->precision > 0)
		puthexanbr_prec(ops, nbr_ops, upper);
	else
		puthexanbr_no_prec(ops, nbr_ops, upper);
	ops->tp->chrs_written += nbr_ops->nbr_size;
}

void		ft_printf_puthexanbr(t_fmt_ops *ops)
{
	t_nbr		nbr_ops;
	int			upper;

	nbr_ops.nbr = ft_printf_get_unbr(ops);
	nbr_ops.nbr_size = ft_printf_get_unbr_length(nbr_ops.nbr, 16);
	upper = !ft_strncmp(ops->type, TYPE_HEXA_DECIMAL_UPPERCASE, 1);
	if (!nbr_ops.nbr && ops->precision == -1)
		padding_with(ops, (ops->convert) ? 2 : 0, ' ');
	else
		puthexanbr(ops, &nbr_ops, upper);
}
