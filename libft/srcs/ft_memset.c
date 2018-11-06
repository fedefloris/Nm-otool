/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:22:39 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 15:19:41 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)dst;
	if (temp != NULL)
	{
		while (n-- > 0)
		{
			*temp = c;
			temp++;
		}
	}
	return (dst);
}
