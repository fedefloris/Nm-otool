/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:20:12 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/04 19:20:13 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const t_uchar	*s;
	t_uchar			*d;

	s = (t_uchar*)src;
	d = (t_uchar*)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}
