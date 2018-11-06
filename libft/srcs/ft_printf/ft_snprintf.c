/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:15:12 by jwong             #+#    #+#             */
/*   Updated: 2016/04/14 11:21:32 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_info	info;

	if (format == NULL || format[0] == '\0' || str == NULL)
		return (0);
	va_start(info.ap, format);
	info.buff_len = BUFF_SIZE;
	info.char_count = 0;
	info.buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (info.buffer != NULL)
	{
		info.buffer[BUFF_SIZE] = '\0';
		ft_get_formatted_string(&info, (char *)format);
		str = ft_memcpy(str, info.buffer, size);
		free(info.buffer);
		va_end(info.ap);
		return (size);
	}
	va_end(info.ap);
	return (ERROR);
}
