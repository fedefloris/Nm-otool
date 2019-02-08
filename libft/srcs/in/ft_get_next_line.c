/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:34:35 by ffloris           #+#    #+#             */
/*   Updated: 2018/10/06 21:34:13 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		save_next(t_buff *buff, char **line, char *occ)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;

	temp1 = ft_strnew(BUFF_SIZE);
	ft_strcpy(temp1, occ + 1);
	temp2 = ft_strsub(buff->content, 0, occ - buff->content);
	temp3 = *line;
	*line = ft_strjoin(*line, temp2);
	free(temp2);
	free(temp3);
	free(buff->content);
	buff->content = temp1;
}

static int		get_next(t_buff *buff, char **line)
{
	char	*temp1;
	char	*occ;

	occ = ft_strchr(buff->content, '\n');
	if (occ)
	{
		save_next(buff, line, occ);
		if (*line == NULL)
		{
			if ((*line = ft_strnew(1)))
				**line = '\n';
		}
		return (1);
	}
	temp1 = *line;
	*line = ft_strjoin(temp1, buff->content);
	free(temp1);
	ft_strclr(buff->content);
	return (0);
}

static t_buff	*setup_buff(t_buff **buffs, const int fd, t_buff *buff)
{
	if (!(buff))
	{
		if (!(buff = (t_buff*)ft_memalloc(sizeof(t_buff))))
			return (NULL);
	}
	else
	{
		buff->next = (t_buff*)ft_memalloc(sizeof(t_buff));
		buff = buff->next;
		if (!buff)
			return (NULL);
	}
	if (!(*buffs))
		*buffs = buff;
	buff->next = NULL;
	buff->fd = fd;
	if (!(buff->content = ft_strnew(BUFF_SIZE)))
		return (NULL);
	return (buff);
}

static t_buff	*get_buff(t_buff **buffs, const int fd)
{
	t_buff	*buff;

	buff = *buffs;
	while (buff)
	{
		if (buff->fd == fd)
			return (buff);
		if (buff->next == NULL)
			break ;
		buff = buff->next;
	}
	return (setup_buff(buffs, fd, buff));
}

int				ft_get_next_line(const int fd, char **line)
{
	static	t_buff	*buffs = NULL;
	t_buff			*buff;
	int				rs;
	int				gt;

	if (BUFF_SIZE <= 0 || !line || fd < 0)
		return (-1);
	*line = NULL;
	if (!(buff = get_buff(&buffs, fd)))
		return (-1);
	if (!(gt = get_next(buff, line)))
	{
		while ((rs = read(fd, buff->content, BUFF_SIZE)) > 0)
		{
			if (get_next(buff, line))
				return (1);
		}
		if (*line && **line && !rs)
		{
			free(buff->content);
			return (1);
		}
		return ((rs == -1) ? -1 : 0);
	}
	return ((gt != 0) ? 1 : -1);
}
