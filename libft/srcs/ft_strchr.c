/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:23:45 by jwong             #+#    #+#             */
/*   Updated: 2015/11/27 15:25:21 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = c;
	while (*s)
	{
		if (*s == letter)
			return ((char *)s);
		s++;
	}
	if (*s == letter)
		return ((char *)s);
	return (NULL);
}
