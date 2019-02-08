/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_o_fat_64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:36 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:36 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static bool		mach_fat_64_launch_mach_o(t_nm_otool *nm_otool,
	t_file file_data, struct fat_arch_64 *arch,
	t_obj_handler mach_o_function)
{
	bool		status;

	if (!STRUCT_IS_SAFE(arch))
		return (ERROR_LOG("fat: arch beyond binary"));
	ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
	nm_otool->file.name = file_data.name;
	nm_otool->file.size = SWAP_ENDIAN_FORCE(arch->size);
	nm_otool->file.memory = file_data.memory + SWAP_ENDIAN_FORCE(arch->offset);
	if ((nm_otool->file.end_of_file = nm_otool->file.memory
			+ nm_otool->file.size - 1) > file_data.end_of_file)
		return (ERROR_LOG("fat: arch->size bad size."));
	if (!ft_strncmp(nm_otool->file.memory, ARMAG, SARMAG))
	{
		nm_otool->file.format = ARCHIVE;
		status = archive_handler(nm_otool);
		nm_otool->file = file_data;
		return (status);
	}
	return (set_file_info_on_macos(nm_otool) && mach_o_function(nm_otool));
}

static bool		mach_fat_64_handle_format(t_nm_otool *nm_otool,
	struct fat_arch_64 *arch, uint32_t nfat_arch)
{
	t_file				file_data;
	struct fat_arch_64	*type_64;
	struct fat_arch_64	*type_32;

	file_data = nm_otool->file;
	type_64 = NULL;
	type_32 = NULL;
	while (nfat_arch-- && !type_64)
	{
		if (!STRUCT_IS_SAFE(arch))
			return (ERROR_LOG("fat: arch beyond binary"));
		if (!type_64 && SWAP_ENDIAN_FORCE(arch->cputype) == CPU_TYPE_X86_64)
			type_64 = arch;
		else if (!type_32 && SWAP_ENDIAN_FORCE(arch->cputype) == CPU_TYPE_I386)
			type_32 = arch;
		nm_otool->file = file_data;
		if (!(NEXT_STRUCT(arch)))
			return (ERROR_LOG("fat: next arch beyond binary"));
	}
	if (!type_32 && !type_64)
		return (false);
	return (mach_fat_64_launch_mach_o(nm_otool, file_data, type_64, (type_64)
		? mach_o_obj_handler_64 : mach_o_obj_handler_32));
}

bool			mach_o_fat_64(t_nm_otool *nm_otool)
{
	struct fat_header	*header;
	struct fat_arch_64	*arch;
	uint32_t			nfat_arch;

	if (!SET(header, nm_otool->file.memory)
		|| !STRUCT_IS_SAFE(header))
		return (ERROR_LOG("fat: header beyond binary"));
	nfat_arch = SWAP_ENDIAN_FORCE(header->nfat_arch);
	if (!SET(arch, header + sizeof(*header)))
		return (ERROR_LOG("fat: did not find arch within binary"));
	return (mach_fat_64_handle_format(nm_otool, arch, nfat_arch));
}
