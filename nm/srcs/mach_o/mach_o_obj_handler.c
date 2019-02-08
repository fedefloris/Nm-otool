/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_o_obj_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:27 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:27:28 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

bool		mach_o_obj_handler(t_nm_otool *nm_otool)
{
	mach_o_get_sections_32(NULL, NULL, NULL, true);
	mach_o_get_sections_64(NULL, NULL, NULL, true);
	if (IS_MACH_O_32(nm_otool->file.format))
		return (mach_o_obj_handler_32(nm_otool));
	if (IS_MACH_O_64(nm_otool->file.format))
		return (mach_o_obj_handler_64(nm_otool));
	if (IS_MACH_O_FAT_32(nm_otool->file.format))
		return (mach_o_fat_32(nm_otool));
	if (IS_MACH_O_FAT_64(nm_otool->file.format))
		return (mach_o_fat_64(nm_otool));
	return (ERROR_LOG("Unrecognized format"));
}
