/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:00:52 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 18:35:41 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (s != NULL)
	{
		ret = (char *)malloc(sizeof(*ret) * ft_strlen(s) + 1);
		if (ret != NULL)
		{
			i = 0;
			while (*s)
			{
				ret[i] = f(i, *s);
				i++;
				s++;
			}
			ret[i] = '\0';
		}
		return (ret);
	}
	return (NULL);
}
