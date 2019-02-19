/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:44:15 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/25 15:14:46 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putprefix(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (nbr_ops->neg)
		ft_putchar_fd('-', ops->tp->fd);
	else if (nbr_ops->sign && ops->sign)
		ft_putchar_fd('+', ops->tp->fd);
	else if (nbr_ops->sign && ops->spaces)
		ft_putchar_fd(' ', ops->tp->fd);
}

static void	putnbr_no_prec(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	if (ops->left)
	{
		putprefix(ops, nbr_ops);
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 10, 0);
		padding_with(ops, nbr_ops->nbr_size, ' ');
	}
	else if (ops->zeros && ops->precision != -1)
	{
		putprefix(ops, nbr_ops);
		padding_with(ops, nbr_ops->nbr_size, '0');
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 10, 0);
	}
	else
	{
		padding_with(ops, nbr_ops->nbr_size, ' ');
		putprefix(ops, nbr_ops);
		ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 10, 0);
	}
}

static void	putnbr_prec(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	int		off;

	off = ops->precision - nbr_ops->nbr_size +
		nbr_ops->neg + nbr_ops->pos + nbr_ops->space;
	off = ft_clamp(off, 0, off);
	if (!ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
	putprefix(ops, nbr_ops);
	if (nbr_ops->neg || nbr_ops->pos || nbr_ops->space)
		nbr_ops->nbr_size--;
	padding_with_prec(ops, nbr_ops->nbr_size, '0');
	if (nbr_ops->neg || nbr_ops->pos || nbr_ops->space)
		nbr_ops->nbr_size++;
	ft_printf_put_uintmax_nbr(nbr_ops->nbr, ops->tp->fd, 10, 0);
	if (ops->left && ops->width)
		padding_with(ops, nbr_ops->nbr_size + off, ' ');
}

static void	putnbr(t_fmt_ops *ops, t_nbr *nbr_ops)
{
	nbr_ops->pos = 0;
	nbr_ops->space = 0;
	if (nbr_ops->sign)
	{
		nbr_ops->pos = ops->sign;
		nbr_ops->space = ops->spaces;
	}
	if (nbr_ops->neg || nbr_ops->pos || nbr_ops->space)
		nbr_ops->nbr_size++;
	if (ops->precision > 0)
		putnbr_prec(ops, nbr_ops);
	else
		putnbr_no_prec(ops, nbr_ops);
	ops->tp->chrs_written += nbr_ops->nbr_size;
}

void		ft_printf_putnbr(t_fmt_ops *ops)
{
	t_nbr		nbr_ops;

	nbr_ops.neg = 0;
	nbr_ops.sign = 0;
	if (!ft_strncmp(ops->type, TYPE_DECIMAL, 1) ||
		!ft_strncmp(ops->type, TYPE_LONG_DECIMAL, 1))
		nbr_ops.nbr = ft_printf_get_unbr(ops);
	else
	{
		nbr_ops.nbr = ft_printf_get_nbr(ops, &(nbr_ops.neg));
		nbr_ops.sign = 1;
	}
	nbr_ops.nbr_size = ft_printf_get_unbr_length(nbr_ops.nbr, 10);
	if (!nbr_ops.nbr && ops->precision == -1)
	{
		putprefix(ops, &nbr_ops);
		padding_with(ops, (nbr_ops.neg ||
		(nbr_ops.sign && (ops->sign || ops->spaces))) ? 1 : 0, ' ');
		if (nbr_ops.neg || (nbr_ops.sign && (ops->sign || ops->spaces)))
			ops->tp->chrs_written++;
	}
	else
		putnbr(ops, &nbr_ops);
}
