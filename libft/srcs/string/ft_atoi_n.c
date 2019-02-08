/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:54:38 by ffloris           #+#    #+#             */
/*   Updated: 2018/05/16 11:17:40 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_n(const char *str, size_t n)
{
	unsigned int	nbr;
	int				neg;

	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else
	{
		neg = 0;
		if (*str == '+')
			str++;
	}
	nbr = 0;
	while (ft_isdigit(*str) && n--)
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg) ? -(int)nbr : (int)nbr;
}
