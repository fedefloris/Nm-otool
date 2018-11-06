/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:31:09 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 17:41:00 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	total;
	size_t	i;

	d_len = ft_strlen(dest);
	if (d_len < size)
	{
		total = size - (d_len + 1);
		d_len += ft_strlen(src);
		i = 0;
		while (dest[i])
			i++;
		while ((*src != '\0') && (total-- > 0))
		{
			dest[i] = *src;
			i++;
			src++;
		}
		dest[i] = '\0';
	}
	else
		return (size + ft_strlen(src));
	return (d_len);
}
