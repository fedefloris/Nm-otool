/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:25:49 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/25 11:04:43 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printf_putid(t_fmt_ops *ops)
{
	size_t	s_size;
	size_t	temp;

	temp = ft_strlen(PUT_ID);
	if (!(s_size = ops->precision) || s_size > temp)
		s_size = temp;
	if (ops->left)
		ft_putnstr_fd(PUT_ID, ops->tp->fd, s_size);
	add_padding(ops, s_size);
	if (!ops->left)
		ft_putnstr_fd(PUT_ID, ops->tp->fd, s_size);
	ops->tp->chrs_written += s_size;
}
