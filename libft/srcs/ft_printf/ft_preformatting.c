/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preformatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:50:34 by jwong             #+#    #+#             */
/*   Updated: 2016/04/14 10:14:46 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_get_options(t_format *format, char *s, int **i)
{
	char	*tmp;

	**i += ft_store_flags(format, s, **i);
	**i += ft_store_width(format, s, **i);
	**i += ft_store_precision(format, s, **i);
	tmp = &s[**i];
	**i += ft_store_lmod(format, tmp, s, **i);
}

int		ft_get_format_string(t_info *info, char *str, int *i)
{
	t_format	format;

	ft_bzero(&format, sizeof(format));
	(format).precision = -1;
	(*i)++;
	ft_get_options(&format, str, &i);
	if (ft_format_processing(info, &format, str[*i]) == FALSE)
	{
		ft_cleanup(&format);
		return (FALSE);
	}
	(*i)++;
	ft_cleanup(&format);
	return (TRUE);
}

int		ft_get_formatted_string(t_info *info, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0'
					|| ft_get_format_string(info, str, &i) == FALSE)
				i++;
		}
		else
		{
			ft_fill_buffer(info, &str[i], 1);
			i++;
		}
	}
	return (TRUE);
}
