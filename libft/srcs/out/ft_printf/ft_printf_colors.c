/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:14:39 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/24 16:51:20 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_colors.h"

static void	move_next(t_printf *tp)
{
	while (tp->s[tp->index] && ft_strncmp(END_COLORS_ID,
								&tp->s[tp->index++], 1) != 0)
		;
}

static void	print_colors(t_printf *tp)
{
	int	i;
	int id_size;

	i = 0;
	while (g_colors[i].id)
	{
		if (ft_isspace(tp->s[tp->index]))
		{
			i = 0;
			tp->index++;
		}
		else
		{
			id_size = ft_strlen(g_colors[i].id);
			if (!ft_strncmp(g_colors[i].id, &tp->s[tp->index], id_size))
			{
				ft_putstr_fd(g_colors[i].value, tp->fd);
				tp->index += id_size;
				break ;
			}
			i++;
		}
	}
	if (g_colors[i].id && ft_strcmp(g_colors[i].id, COLORS_ID) != 0)
		move_next(tp);
}

void		ft_printf_colors(t_printf *tp)
{
	if (!ft_strncmp(END_COLORS_ID, &tp->s[tp->index], 1))
	{
		ft_putstr_fd(END_COLORS_ID, tp->fd);
		tp->index++;
		return ;
	}
	print_colors(tp);
}
