/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:40:36 by jwong             #+#    #+#             */
/*   Updated: 2015/12/09 15:46:21 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	while (n-- > 0 && *temp2 != (unsigned char)c)
	{
		*temp1 = *temp2;
		temp1++;
		temp2++;
	}
	if (*temp2 == (unsigned char)c)
	{
		*temp1 = *temp2;
		return (++temp1);
	}
	return (NULL);
}
