/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:26:15 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 20:30:41 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_add_precision(t_format *format, char **fstr)
{
	char	*tmp;
	char	*padding;
	int		len;

	(*format).flag_zero = 0;
	if ((len = (*format).precision - (int)ft_strlen(*fstr)) > 0)
	{
		tmp = *fstr;
		padding = ft_padding(len, '0');
		*fstr = ft_strjoin(padding, *fstr);
		free(tmp);
		free(padding);
	}
}

void	ft_add_precision_s(t_format *format, char **fstr)
{
	char	*tmp;
	char	*new_str;

	tmp = *fstr;
	new_str = (char *)malloc(sizeof(*new_str) * (*format).precision + 1);
	if (new_str)
	{
		new_str = ft_memcpy(new_str, *fstr, (*format).precision);
		new_str[(*format).precision] = '\0';
		*fstr = new_str;
		free(tmp);
	}
}
