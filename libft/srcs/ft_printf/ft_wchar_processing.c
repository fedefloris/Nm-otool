/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:36:09 by jwong             #+#    #+#             */
/*   Updated: 2016/04/22 17:51:25 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_wchar_processing1(int num)
{
	char	str[2];

	if (num <= 0x7F)
	{
		str[0] = (char)num;
		str[1] = '\0';
		return (ft_strdup(str));
	}
	return (NULL);
}

static char	*ft_wchar_processing2(int num)
{
	char	str[3];

	if (num <= 0x7FF)
	{
		str[0] = (((num & 0x07c0) >> 6) + 0xc0);
		str[1] = ((num & 0x003F) + 0x80);
		str[2] = '\0';
		return (ft_strdup(str));
	}
	return (NULL);
}

static char	*ft_wchar_processing3(int num)
{
	char	str[4];

	if (num <= 0xFFFF)
	{
		str[0] = (((num & 0xF000) >> 12) + 0xE0);
		str[1] = (((num & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((num & 0x003F) + 0x80);
		str[3] = '\0';
		return (ft_strdup(str));
	}
	return (NULL);
}

static char	*ft_wchar_processing4(int num)
{
	char	str[5];

	if (num <= 0x10FFFF)
	{
		str[0] = (((num & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((num & 0x03F000) >> 12) + 0x80);
		str[2] = (((num & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((num & 0x003F) + 0x80);
		str[4] = '\0';
		return (ft_strdup(str));
	}
	return (NULL);
}

char		*ft_get_wchar(int num)
{
	if (num < 0)
		return (ft_strdup(""));
	if (num <= 0x7F)
		return (ft_wchar_processing1(num));
	else if (num <= 0x7FF)
		return (ft_wchar_processing2(num));
	else if (num <= 0xFFFF)
		return (ft_wchar_processing3(num));
	else if (num <= 0x10FFFF)
		return (ft_wchar_processing4(num));
	return (ft_strdup(""));
}
