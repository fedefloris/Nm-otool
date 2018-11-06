/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:47:13 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 18:34:44 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	if (s != NULL)
	{
		ret = (char *)malloc(sizeof(*ret) * ft_strlen(s) + 1);
		if (ret != NULL)
		{
			i = 0;
			while (*s)
			{
				ret[i] = f(*s);
				i++;
				s++;
			}
			ret[i] = '\0';
		}
		return (ret);
	}
	return (NULL);
}
