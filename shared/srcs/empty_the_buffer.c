/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_the_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:11 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:12 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include <unistd.h>

void		empty_the_buffer(t_buffer *buffer)
{
	if (!buffer->content_index)
		return ;
	write(1, buffer->content, buffer->content_index);
	CONFIG_BUFFER(buffer);
}
