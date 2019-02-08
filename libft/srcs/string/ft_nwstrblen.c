/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwstrblen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:01:08 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 12:53:52 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nwstrblen(const wchar_t *s, size_t n)
{
	size_t	size;
	long	i;

	i = (long)n;
	size = 0;
	while (*s != L'\0')
	{
		i -= ft_wcharlen(*s);
		if (i < 0)
			break ;
		size += ft_wcharlen(*s);
		s++;
	}
	return (size);
}
