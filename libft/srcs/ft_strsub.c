/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:41:18 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 18:40:28 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (s != NULL)
	{
		ret = (char *)malloc(sizeof(*ret) * len + 1);
		if (ret != NULL)
		{
			i = 0;
			while (len-- > 0)
			{
				ret[i] = s[start];
				i++;
				start++;
			}
			ret[i] = '\0';
		}
		return (ret);
	}
	return (NULL);
}
