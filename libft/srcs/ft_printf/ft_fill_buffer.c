/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:46:22 by jwong             #+#    #+#             */
/*   Updated: 2016/04/22 12:08:17 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_buffer(t_info *info, char *str, size_t n)
{
	char	*tmp;
	size_t	initial_len;

	initial_len = (*info).buff_len;
	while (((*info).char_count + n) > (*info).buff_len)
		(*info).buff_len += BUFF_SIZE;
	if (((*info).char_count + n) > initial_len)
	{
		tmp = (*info).buffer;
		(*info).buffer = ft_remalloc((*info).buffer,
				initial_len, (*info).buff_len);
		free(tmp);
		if ((*info).buffer == NULL)
			exit(1);
	}
	while (n > 0)
	{
		(*info).buffer[(*info).char_count] = *str;
		(*info).char_count++;
		str++;
		n--;
	}
}
