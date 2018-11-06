/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justified.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:31:28 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 20:35:52 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_padding(int len, char c)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * len + 1);
	if (str)
	{
		i = 0;
		while (i < len)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (ft_strdup(""));
}

void	ft_left_adjust(char **fstr, int size)
{
	char	*tmp;
	char	*padding;

	tmp = *fstr;
	padding = ft_padding(size, ' ');
	*fstr = ft_strjoin(*fstr, padding);
	free(tmp);
	free(padding);
}

void	ft_right_adjust(char **fstr, int size, char c)
{
	char	*tmp;
	char	*padding;

	tmp = *fstr;
	padding = ft_padding(size, c);
	*fstr = ft_strjoin(padding, *fstr);
	free(tmp);
	free(padding);
}
