/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:44:40 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/05 13:44:41 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *result, char const *s1, char const *s2)
{
	size_t	count;

	count = 0;
	while ((s1 && *s1 != '\0') || (s2 && *s2 != '\0'))
	{
		if (s1 && *s1 != '\0')
			result[count] = *s1++;
		else if (s2 && *s2 != '\0')
			result[count] = *s2++;
		count++;
	}
	result[count] = '\0';
	return (result);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;

	result = NULL;
	if (!s1 && !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (s1_size + s2_size == 0)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (NULL);
	return (join(result, s1, s2));
}
