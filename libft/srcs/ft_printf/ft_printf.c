/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:59:35 by jwong             #+#    #+#             */
/*   Updated: 2016/04/14 10:13:59 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_info	info;

	if (format == NULL || format[0] == '\0')
		return (0);
	va_start(info.ap, format);
	info.buff_len = BUFF_SIZE;
	info.char_count = 0;
	info.buffer = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (info.buffer != NULL)
	{
		ft_get_formatted_string(&info, (char *)format);
		write(1, info.buffer, info.char_count);
		free(info.buffer);
		va_end(info.ap);
		return (info.char_count);
	}
	va_end(info.ap);
	return (ERROR);
}
