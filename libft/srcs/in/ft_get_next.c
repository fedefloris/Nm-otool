/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:34:35 by ffloris           #+#    #+#             */
/*   Updated: 2018/10/06 21:33:52 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get(char buff, char **line, size_t size)
{
	char	*temp;

	temp = *line;
	*line = ft_strnew(size);
	if (temp)
		ft_strcpy(*line, temp);
	(*line)[size - 1] = buff;
	if (temp)
		free(temp);
}

int			ft_get_next(const int fd, char **line, char c)
{
	char		buff;
	ssize_t		res;
	size_t		size;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	size = 0;
	while ((res = read(fd, &buff, 1)) > 0)
	{
		if (buff == c)
			return (1);
		get(buff, line, ++size);
	}
	return (0);
}
