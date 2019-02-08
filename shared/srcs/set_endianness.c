/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_endianness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:53 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:54 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

/*
** Returns:
** 0 in case of big endian machine
** 1 in case of little endian machine
*/

static int	get_endianness(void)
{
	unsigned int x;

	x = 1;
	return (*(char*)&x);
}

void		set_endianness(t_nm_otool *nm_otool,
	int file_endianness)
{
	nm_otool->file.reversed_endian = false;
	if (file_endianness == LITTLE_ENDIAN_FILE
		&& !get_endianness())
		nm_otool->file.reversed_endian = true;
	else if (file_endianness == BIG_ENDIAN_FILE
		&& get_endianness())
		nm_otool->file.reversed_endian = true;
}
