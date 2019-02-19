/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars_written.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:55:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 14:48:51 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printf_chars_written(t_fmt_ops *ops)
{
	int	*n;

	n = va_arg(*(ops->tp->params), int*);
	if (n)
		*n = ops->tp->chrs_written;
}
