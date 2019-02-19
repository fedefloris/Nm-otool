/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:22:59 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/04 19:23:02 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_size;
	char	*dup;

	s1_size = ft_strlen(s1);
	if (!(dup = (char*)malloc(sizeof(char) * (s1_size + 1))))
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
