/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:23:41 by jwong             #+#    #+#             */
/*   Updated: 2015/12/02 14:48:33 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
    size_t          i;

	ptr = (unsigned char *)malloc(sizeof(*ptr) * size);
	if (ptr != NULL)
	{
		i = 0;
		while (size > 0)
		{
			ptr[i] = '\0';
			i++;
			size--;
		}
	}
	return ((void *)ptr);
}
