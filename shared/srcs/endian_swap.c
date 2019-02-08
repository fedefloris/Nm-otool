/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:13 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:17 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

uint64_t			endian_swap(uint64_t value,
		size_t size, bool reversed_endian)
{
	uint64_t		new_value;
	unsigned char	*new_tmp;
	unsigned char	*tmp;
	int				i;

	if (!reversed_endian || size > MAX_ENDIAN_SWAP_SIZE)
		return (value);
	new_value = 0;
	new_tmp = (unsigned char *)&new_value;
	tmp = (unsigned char *)&value;
	i = 0;
	while (--size)
		new_tmp[i++] = tmp[size];
	new_tmp[i++] = tmp[size];
	return (new_value);
}
