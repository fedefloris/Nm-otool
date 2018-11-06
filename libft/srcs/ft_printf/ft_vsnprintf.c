/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:56:00 by jwong             #+#    #+#             */
/*   Updated: 2016/04/19 10:56:07 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_info	info;

	if (format == NULL || format[0] == '\0' || str == NULL)
		return (0);
	va_copy(info.ap, ap);
	info.buff_len = BUFF_SIZE;
	info.char_count = 0;
	info.buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (info.buffer != NULL)
	{
		info.buffer[BUFF_SIZE] = '\0';
		ft_get_formatted_string(&info, (char *)format);
		str = ft_memcpy(str, info.buffer, size);
		free(info.buffer);
		return (size);
	}
	return (ERROR);
}
