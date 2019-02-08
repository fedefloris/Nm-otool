/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:47:15 by exam              #+#    #+#             */
/*   Updated: 2018/03/02 12:59:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_dimensions(int value, int base, unsigned int *value_size,
															int *length)
{
	unsigned int	value_u;

	if (value < 0)
		value_u = -value;
	else
		value_u = value;
	*value_size = 1;
	*length = 1;
	while ((value_u /= base) > 0)
	{
		*value_size *= base;
		(*length)++;
	}
}

static void	sign_checker(int value, int base, int *neg, unsigned int *value_u)
{
	*neg = 0;
	if (value < 0)
	{
		if (base == 10)
			*neg = 1;
		*value_u = -value;
	}
	else
		*value_u = value;
}

static char	*itoa_base(int value, int base, unsigned int value_size,
															int length)
{
	char			*res;
	int				out;
	int				neg;
	int				i;
	unsigned int	value_u;

	sign_checker(value, base, &neg, &value_u);
	if (!(res = (char*)malloc(sizeof(char) * (length + neg + 1))))
		return (NULL);
	i = 0;
	if (neg)
		res[i++] = '-';
	while (value_size > 0)
	{
		out = value_u / value_size;
		if (out > 9 && out != 16)
			out += 'A' - '9' - 1;
		res[i++] = '0' + out;
		value_u %= value_size;
		value_size /= base;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_itoa_base(int value, int base)
{
	char			*res;
	unsigned int	value_size;
	int				length;

	if (base < 2 || base > 16)
		return (NULL);
	set_dimensions(value, base, &value_size, &length);
	res = itoa_base(value, base, value_size, length);
	return (res);
}
