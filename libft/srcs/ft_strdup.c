/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:57:30 by jwong             #+#    #+#             */
/*   Updated: 2015/12/09 14:19:08 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		count;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str != NULL)
	{
		count = 0;
		while (s1[count])
		{
			str[count] = s1[count];
			count++;
		}
		str[count] = '\0';
	}
	return (str);
}
