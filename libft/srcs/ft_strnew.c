/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:50:42 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 18:13:46 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str != NULL)
	{
		i = 0;
		while (size > 0)
		{
			str[i] = '\0';
			i++;
			size--;
		}
		str[i] = '\0';
	}
	return (str);
}
