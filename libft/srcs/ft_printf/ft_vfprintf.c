/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:55:04 by jwong             #+#    #+#             */
/*   Updated: 2016/04/19 10:55:28 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	t_info	info;

	if (format == NULL || format[0] == '\0')
		return (0);
	va_copy(info.ap, ap);
	info.buff_len = BUFF_SIZE;
	info.char_count = 0;
	info.buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (info.buffer != NULL)
	{
		info.buffer[BUFF_SIZE] = '\0';
		ft_get_formatted_string(&info, (char *)format);
		stream = ft_memcpy(stream, info.buffer, info.char_count);
		free(info.buffer);
		return (info.char_count);
	}
	return (ERROR);
}
