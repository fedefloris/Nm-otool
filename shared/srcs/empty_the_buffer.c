/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_the_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:11 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:12 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include <unistd.h>

void		empty_the_buffer(t_buffer *buffer)
{
	write(1, buffer->content, buffer->content_index);
	config_buffer(buffer);
}
