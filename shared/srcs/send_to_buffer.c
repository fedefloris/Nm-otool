/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:44 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:49 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include <stdarg.h>

static void		send_str_to_buffer(t_buffer *buffer, char *str)
{
	while (*str)
	{
		if (buffer->content_index >= BUFFER_SIZE)
			empty_the_buffer(buffer);
		buffer->content[buffer->content_index++] = *str++;
	}
}

void			send_to_buffer(t_buffer *buffer, ...)
{
	va_list		args;
	char		*str;

	va_start(args, buffer);
	while ((str = va_arg(args, char*)))
		send_str_to_buffer(buffer, str);
	va_end(args);
}
