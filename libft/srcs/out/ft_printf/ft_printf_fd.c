/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:32:58 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 11:29:47 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	move_next(t_printf *tp)
{
	while (tp->s[tp->index] &&
			ft_strncmp(END_FD_ID, &tp->s[tp->index++], 1) != 0)
		;
}

void		ft_printf_fd(t_printf *tp)
{
	int	n;

	while (ft_isspace(tp->s[tp->index]))
		tp->index++;
	if (!ft_strncmp(tp->s + tp->index, FD_ID, 1))
	{
		ft_putchar_fd(*FD_ID, tp->fd);
		tp->index++;
		return ;
	}
	if (!ft_strncmp(FD_PARAM, tp->s + tp->index, 1))
		tp->fd = va_arg(*(tp->params), int);
	else
	{
		n = 0;
		while (ft_isdigit(tp->s[tp->index + n]))
			n++;
		tp->fd = ft_atoi_n(tp->s + tp->index, n);
		tp->index += n;
	}
	move_next(tp);
}
