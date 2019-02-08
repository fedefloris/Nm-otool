/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:23:54 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/04 19:23:55 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < size)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < size)
		{
			if (j == len - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
