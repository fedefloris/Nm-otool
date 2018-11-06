/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:05:26 by jwong             #+#    #+#             */
/*   Updated: 2016/04/19 10:59:23 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_add_alignment_c(t_format *format, char **fstr, int len)
{
	if ((*format).flag_minus != 0)
	{
		ft_left_adjust(fstr, len);
		return (TRUE);
	}
	if ((*format).flag_zero != 0)
	{
		ft_right_adjust(fstr, len, '0');
		return (TRUE);
	}
	ft_right_adjust(fstr, len, ' ');
	return (TRUE);
}

int		ft_add_alignment_p(t_format *format, char **fstr, int len, char c)
{
	if ((*format).flag_sharp != 0)
		len -= 2;
	if ((*format).flag_minus != 0)
	{
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(fstr, c);
		ft_left_adjust(fstr, len);
		return (TRUE);
	}
	if ((*format).flag_zero != 0 && (*format).precision == -1)
	{
		ft_right_adjust(fstr, len, '0');
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(fstr, c);
		return (TRUE);
	}
	if ((*format).flag_sharp != 0)
		ft_sharp_handler(fstr, c);
	ft_right_adjust(fstr, len, ' ');
	return (TRUE);
}

int		ft_add_alignment_invalid(t_format *format, t_info *info, char **fstr,
		int len)
{
	if ((*format).flag_minus != 0)
	{
		ft_left_adjust(fstr, len);
		ft_fill_buffer(info, *fstr, ft_strlen(*fstr));
		free(*fstr);
		return (TRUE);
	}
	if ((*format).flag_zero != 0)
	{
		ft_right_adjust(fstr, len, '0');
		ft_fill_buffer(info, *fstr, ft_strlen(*fstr));
		free(*fstr);
		return (TRUE);
	}
	ft_right_adjust(fstr, len, ' ');
	ft_fill_buffer(info, *fstr, ft_strlen(*fstr));
	free(*fstr);
	return (TRUE);
}
