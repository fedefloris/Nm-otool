/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:36:34 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 20:40:12 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_add_sign(t_format *format, char **fstr)
{
	char	*tmp;

	if ((*format).neg_sign != 0)
	{
		tmp = *fstr;
		*fstr = ft_strjoin("-", *fstr);
		free(tmp);
	}
	else if ((*format).flag_plus != 0 && (*format).neg_sign == 0)
	{
		tmp = *fstr;
		*fstr = ft_strjoin("+", *fstr);
		free(tmp);
	}
	else if ((*format).flag_space != 0 && (*format).neg_sign == 0)
	{
		tmp = *fstr;
		*fstr = ft_strjoin(" ", *fstr);
		free(tmp);
	}
}

void	ft_sharp_handler(char **fstr, char c)
{
	char	*tmp;

	if (c == 'o')
	{
		tmp = *fstr;
		*fstr = ft_strjoin("0", *fstr);
		free(tmp);
	}
	else if (c == 'x')
	{
		tmp = *fstr;
		*fstr = ft_strjoin("0x", *fstr);
		free(tmp);
	}
	else if (c == 'X')
	{
		tmp = *fstr;
		*fstr = ft_strjoin("0X", *fstr);
		free(tmp);
	}
}
