/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:35:37 by ffloris           #+#    #+#             */
/*   Updated: 2018/05/03 13:35:55 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinteger(char *str)
{
	size_t	str_size;
	size_t	i;
	long	n;

	i = 0;
	str_size = ft_strlen(str);
	while (str[i++] == '0')
		str_size--;
	if (!ft_isnumber(str))
		return (0);
	n = ft_atoi(str);
	if (str_size > 11 || n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}
