/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:01:02 by jwong             #+#    #+#             */
/*   Updated: 2015/12/19 16:20:54 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ret;

	if (s1 != NULL && s2 != NULL)
	{
		ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (ret != NULL)
		{
			i = 0;
			while (*s1)
			{
				ret[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				ret[i++] = *s2;
				s2++;
			}
			ret[i] = '\0';
		}
		return (ret);
	}
	return (NULL);
}
