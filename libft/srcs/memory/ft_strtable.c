/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:41:14 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/11 10:18:43 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strtable(size_t row_size, size_t col_size)
{
	char	**res;
	size_t	i;

	if (!(res = (char**)malloc(sizeof(char*) * (row_size + 1))))
		return (NULL);
	i = 0;
	while (i < row_size)
	{
		if (!(res[i] = ft_strnew(col_size)))
		{
			ft_strdel_table(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
