/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 10:33:48 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/25 13:52:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_printf	setup(const char *s, va_list *params)
{
	t_printf	tp;

	tp.s = s;
	tp.params = params;
	tp.index = 0;
	tp.fd = 1;
	tp.chrs_written = 0;
	tp.exit = 0;
	return (tp);
}

int				ft_printf(const char *s, ...)
{
	t_printf	tp;
	va_list		params;
	int			result;

	if (!s)
		return (-1);
	va_start(params, s);
	tp = setup(s, &params);
	result = ft_printf_parse(&tp);
	va_end(params);
	return (result);
}
