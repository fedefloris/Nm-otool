/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:22:04 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/04 19:22:07 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	s1_size;
	size_t	i;

	i = 0;
	s1_size = ft_strlen(s1);
	while (s2[i])
	{
		s1[s1_size] = s2[i];
		s1_size++;
		i++;
	}
	s1[s1_size] = '\0';
	return (s1);
}
