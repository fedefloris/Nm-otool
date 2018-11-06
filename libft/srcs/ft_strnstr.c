/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:30:21 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 15:32:29 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_ismatch(const char *big, const char *little, size_t stop)
{
	size_t	i;

	i = 0;
	while (*big && little[i] && i < stop)
	{
		if (*big != little[i])
			return (1);
		big++;
		i++;
	}
	if (little[i] == '\0')
		return (0);
	return (1);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (*big && i < len)
	{
		if (ft_ismatch(big, little, len - i) == 0)
			return ((char*)big);
		big++;
		i++;
	}
	return (NULL);
}
