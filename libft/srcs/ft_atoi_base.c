/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:26:00 by jwong             #+#    #+#             */
/*   Updated: 2016/03/28 14:32:17 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_idx(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long		ft_atoi_base(const char *str, char *base)
{
	long long	num;
	int			neg;
	int			idx;
	int			len;

	num = 0;
	neg = 1;
	while ((*str >= 0 && *str <= 31) || *str == 127 || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	len = ft_strlen(base);
	while ((idx = ft_idx(base, *str)) != -1)
	{
		num += idx;
		num *= len;
		str++;
	}
	num = (num / len) * neg;
	return ((long)num);
}
