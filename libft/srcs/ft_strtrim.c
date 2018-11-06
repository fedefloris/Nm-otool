/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:36:35 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 19:19:54 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*ft_trimit(char const *s)
{
	size_t			len;
	unsigned int	i;
	unsigned int	start;

	len = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	if (s[i] == '\0')
		return (ft_strsub(s, start, 1));
	while (s[i])
	{
		i++;
		len++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		len--;
	}
	return (ft_strsub(s, start, len));
}

char			*ft_strtrim(char const *s)
{
	if (s != NULL)
		return (ft_trimit(s));
	return (NULL);
}
