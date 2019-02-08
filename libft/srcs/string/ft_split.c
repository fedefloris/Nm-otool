/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:13:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/06 15:46:26 by akaseris         ###   ########.fr       */
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

static const char	*ft_str_find_next(char const *s)
{
	while (*s && !ft_isspace(*s))
		s++;
	return (s);
}

static int			ft_str_count_splits(char const *s)
{
	int res;

	res = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s)
		{
			res++;
			s = ft_str_find_next(s);
		}
	}
	return (res);
}

char				**ft_split(char const *s)
{
	const char	*next;
	char		**res;
	int			i;

	i = ft_str_count_splits(s);
	if (!i || !(res = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s)
		{
			next = ft_str_find_next(s);
			if (!(res[i] = ft_strsub(s, 0, next - s)))
				return (ft_tabledel(res, i));
			i++;
			s = next;
		}
	}
	res[i] = 0;
	return (res);
}
