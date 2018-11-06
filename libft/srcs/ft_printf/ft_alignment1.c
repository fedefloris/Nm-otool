/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:58:48 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 20:01:47 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_add_alignment_di(t_format *format, char **fstr, int len)
{
	if ((*format).neg_sign != 0
			|| ((*format).flag_plus != 0 && (*format).neg_sign == 0)
			|| ((*format).flag_space != 0 && (*format).neg_sign == 0))
		len -= 1;
	if ((*format).flag_minus != 0)
	{
		ft_add_sign(format, fstr);
		ft_left_adjust(fstr, len);
		return (TRUE);
	}
	if ((*format).flag_zero != 0)
	{
		ft_right_adjust(fstr, len, '0');
		ft_add_sign(format, fstr);
		return (TRUE);
	}
	ft_add_sign(format, fstr);
	ft_right_adjust(fstr, len, ' ');
	return (TRUE);
}

int		ft_add_alignment_o(t_format *format, char **fstr, int len)
{
	if ((*format).flag_sharp != 0)
		len -= 1;
	if ((*format).flag_minus != 0)
	{
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(fstr, 'o');
		ft_left_adjust(fstr, len);
		return (TRUE);
	}
	if ((*format).flag_zero != 0)
	{
		ft_right_adjust(fstr, len, '0');
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(fstr, 'o');
		return (TRUE);
	}
	if ((*format).flag_sharp != 0)
		ft_sharp_handler(fstr, 'o');
	ft_right_adjust(fstr, len, ' ');
	return (TRUE);
}

int		ft_add_alignment_x(t_format *format, char **fstr, int len, char c)
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
	if ((*format).flag_zero != 0)
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

int		ft_add_alignment_u(t_format *format, char **fstr, int len)
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
