/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char **str)
{
	size_t	s_size;
	char	temp;
	char	*s;
	size_t	i;

	if (str && *str && **str)
	{
		i = 0;
		s = *str;
		s_size = ft_strlen(s) - 1;
		while (i < s_size)
		{
			temp = s[i];
			s[i++] = s[s_size];
			s[s_size--] = temp;
		}
	}
}
