/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:41 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:27:43 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

bool		obj_handler(t_nm_otool *nm_otool)
{
	if (IS_ARCHIVE(nm_otool->file.format))
		return (archive_handler(nm_otool));
	if (IS_ELF(nm_otool->file.format))
		return (elf_obj_handler(nm_otool));
	return (MAC_OBJ_HANDLER(nm_otool));
}
