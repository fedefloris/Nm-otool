/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:29:16 by jwong             #+#    #+#             */
/*   Updated: 2015/11/27 15:29:42 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;
	char		chr;
	int			i;

	temp = NULL;
	chr = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			temp = &s[i];
		i++;
	}
	if (s[i] == chr)
		temp = &s[i];
	return ((char *)temp);
}
