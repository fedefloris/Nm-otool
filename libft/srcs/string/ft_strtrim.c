/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:24:26 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/04 19:24:27 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			end;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strnew(0));
	start = 0;
	while (ft_isspace(s[start]))
		start++;
	end = start + ft_strlen(s + start) - 1;
	while (ft_isspace(s[end]) && end > start)
		end--;
	if (end - start + 1 == 0)
		return (ft_strnew(0));
	return (ft_strsub(s, start, end - start + 1));
}
