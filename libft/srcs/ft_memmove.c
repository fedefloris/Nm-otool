/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:32:25 by jwong             #+#    #+#             */
/*   Updated: 2015/12/08 20:29:57 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*dst;

	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		temp = (unsigned char *)src;
		dst = (unsigned char *)dest;
		temp += (n - 1);
		dst += (n - 1);
		while (n-- > 0)
		{
			*dst = *temp;
			dst--;
			temp--;
		}
	}
	return (dest);
}
