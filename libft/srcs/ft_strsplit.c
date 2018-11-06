/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:34:45 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 19:09:14 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	ft_wordcnt(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		words++;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i != 0 && s[i + 1] != '\0')
				if (s[i + 1] != c)
					words++;
		}
		i++;
	}
	return (words);
}

static	size_t	ft_wordlen(char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static	char	*ft_substr(char *s, char c)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(*tmp) * ft_wordlen(s, c) + 1);
	if (tmp != NULL)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			tmp[i] = *s;
			*s = c;
			i++;
			s++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**table;
	char	*cpy;
	size_t	len;
	size_t	count;

	if (s != NULL)
	{
		len = ft_wordcnt(s, c) + 1;
		count = 0;
		table = (char **)malloc(sizeof(char *) * len);
		if (table != NULL)
		{
			cpy = ft_strdup(s);
			if (cpy != NULL)
			{
				while (len-- > 1)
					table[count++] = ft_substr(cpy, c);
				table[count] = NULL;
			}
            free(cpy);
		}
		return (table);
	}
	return (NULL);
}
