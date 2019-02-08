/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:15:40 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 14:12:45 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_two(unsigned int value, int fd)
{
	unsigned char	oct[2];

	oct[0] = (((value & 0x07c0) >> 6) + 0xc0);
	oct[1] = ((value & 0x003F) + 0x80);
	write(fd, oct, 2);
}

static void		put_three(unsigned int value, int fd)
{
	unsigned char	oct[3];

	oct[0] = (((value & 0xF000) >> 12) + 0xE0);
	oct[1] = (((value & 0x0Fc0) >> 6) + 0x80);
	oct[2] = ((value & 0x003F) + 0x80);
	write(fd, oct, 3);
}

static void		put_four(unsigned int value, int fd)
{
	unsigned char	oct[4];

	oct[0] = (((value & 0x1c0000) >> 18) + 0xF0);
	oct[1] = (((value & 0x03F000) >> 12) + 0x80);
	oct[2] = (((value & 0x0Fc0) >> 6) + 0x80);
	oct[3] = ((value & 0x003F) + 0x80);
	write(fd, oct, 4);
}

void			ft_putwchar_fd(wchar_t c, int fd)
{
	unsigned int	value;

	value = (unsigned int)c;
	if (value <= 0x7F)
		write(fd, &value, 1);
	else if (value <= 0x7FF)
		put_two(value, fd);
	else if (value <= 0xFFFF)
	{
		if (value >= 0xD800 && value <= 0xDBFF)
			return ;
		if (value >= 0xDC00 && value <= 0xDFFF)
			return ;
		put_three(value, fd);
	}
	else if (value <= 0x10FFFF)
		put_four(value, fd);
}
