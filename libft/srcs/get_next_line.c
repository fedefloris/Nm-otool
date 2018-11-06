/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:42:06 by jwong             #+#    #+#             */
/*   Updated: 2018/03/22 11:58:13 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/libft.h"

static char		*str_divide(char **str)
{
	char	*ret;
	char	*tmp;
	int		i;

	if ((*str)[0] == '\0')
	{
		*str = NULL;
		return (NULL);
	}
	i = 0;
	while (((*str)[i] != '\0') && ((*str)[i] != '\n'))
		i++;
	ret = ft_strsub(*str, 0, i);
	i += 1;
	if ((tmp = ft_strsub(*str, i, (ft_strlen(*str) - i))) != NULL)
	{
		free(*str);
		if (tmp[0] == '\0')
			*str = NULL;
		else
			*str = ft_strdup(tmp);
		free(tmp);
	}
	return (ret);
}

static void		check_str(char **str, char *ret)
{
	if (*str != NULL)
		*str = ft_strjoin(*str, ret);
	else if (ret[0] != '\0')
		*str = ft_strdup(ret);
	free(ret);
}

static int		read_file(int fd, char **str)
{
	char		*buffer;
	char		*found;
	char		*ret;
	char		*tmp;
	int			bytes_read;

	if ((buffer = (char *)malloc(sizeof(char *) * BUFF_SIZE + 1)) != NULL)
	{
		found = NULL;
		ret = ft_strdup("");
		bytes_read = 1;
		while ((found = ft_strchr(ret, (int)'\n')) == NULL && bytes_read > 0)
		{
			bytes_read = read(fd, buffer, BUFF_SIZE);
			buffer[bytes_read] = '\0';
			tmp = ret;
			ret = ft_strjoin(ret, buffer);
			free(tmp);
		}
		check_str(str, ret);
		free(buffer);
		return (bytes_read);
	}
	return (-1);
}

static int		return_line(int bytes_read, char **str, char ***line)
{
	if (bytes_read > 0)
	{
		if (ft_strchr(*str, (int)'\n'))
			**line = str_divide(str);
		return (1);
	}
	else if (bytes_read == 0 && *str != NULL)
	{
		if (ft_strchr(*str, (int)'\n'))
			**line = str_divide(str);
		else
		{
			**line = ft_strdup(*str);
			free(*str);
			*str = NULL;
		}
		return (1);
	}
	else if (bytes_read == 0 && *str == NULL)
	{
		**line = NULL;
		return (0);
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			bytes_read;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (str != NULL)
		if (ft_strchr(str, (int)'\n') != NULL)
		{
			*line = str_divide(&str);
			return (1);
		}
	bytes_read = read_file(fd, &str);
	return (return_line(bytes_read, &str, &line));
}
