/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:13:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/05 14:13:17 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_tabledel(char **res, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(res[i++]);
	free(res);
	return (NULL);
}

static const char	*ft_str_find_next(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

static int			ft_str_count_splits(char const *s, char c)
{
	int res;

	res = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res++;
			s = ft_str_find_next(s, c);
		}
	}
	return (res);
}

char				**ft_strsplit(char const *s, char c)
{
	const char	*next;
	char		**res;
	int			i;

	i = ft_str_count_splits(s, c);
	if (!i || !(res = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			next = ft_str_find_next(s, c);
			if (!(res[i] = ft_strsub(s, 0, next - s)))
				return (ft_tabledel(res, i));
			i++;
			s = next;
		}
	}
	res[i] = 0;
	return (res);
}
