/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:10:52 by jwong             #+#    #+#             */
/*   Updated: 2016/04/14 11:22:26 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_sprintf(char *str, const char *format, ...)
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
		str = ft_memcpy(str, info.buffer, info.char_count);
		free(info.buffer);
		va_end(info.ap);
		return (info.char_count);
	}
	va_end(info.ap);
	return (ERROR);
}
