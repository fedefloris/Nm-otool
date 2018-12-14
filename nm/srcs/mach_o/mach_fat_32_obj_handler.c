#include "nm_otool.h"
#include "nm.h"

static bool		mach_fat_32_launch_mach_o(t_nm_otool *nm_otool,
	t_file file_data, struct fat_arch *arch,
	t_obj_handler mach_o_function)
{
	if (!STRUCT_IS_SAFE(arch))
		return (ERROR_LOG("fat: arch beyond binary"));
	ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
	nm_otool->file.name = file_data.name;
	nm_otool->file.size = SWAP_ENDIAN_FORCE(arch->size);
	nm_otool->file.memory = file_data.memory + SWAP_ENDIAN_FORCE(arch->offset);
	if ((nm_otool->file.end_of_file = file_data.memory
		+ file_data.size - 1) > file_data.end_of_file) //Check if safe
		return (ERROR_LOG("fat: arch->size bad size."));
	nm_otool->file.endian_is_reversed = file_data.endian_is_reversed;
	return (mach_o_function(nm_otool));
}

static bool		mach_fat_32_handle_format(t_nm_otool *nm_otool,
	struct fat_arch *arch, uint32_t nfat_arch)
{
	t_file			file_data;

	file_data = nm_otool->file;//
	while (nfat_arch--)
	{
		if (!STRUCT_IS_SAFE(arch))
			return (ERROR_LOG("fat: arch beyond binary"));
		if (SWAP_ENDIAN_FORCE(arch->cputype) == CPU_TYPE_X86_64)
		{
			if (mach_fat_32_launch_mach_o(nm_otool, file_data, arch, &mach_o_64_obj_handler))
				return (true);
		}
		else if (SWAP_ENDIAN_FORCE(arch->cputype) == CPU_TYPE_I386)
		{
			if (mach_fat_32_launch_mach_o(nm_otool, file_data, arch, &mach_o_32_obj_handler))
				return (true);
		}
		return (ERROR_LOG("fat: bad arch->cputype"));
		nm_otool->file = file_data;
		if (!(NEXT_STRUCT(arch)))
			return (ERROR_LOG("fat: next arch beyond binary"));
	}
	return (false);
}

bool			mach_fat_32_obj_handler(t_nm_otool *nm_otool)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	uint32_t			nfat_arch;

	if (!SET(header, nm_otool->file.memory))
		return (ERROR_LOG("fat: header beyond binary"));
	if (!STRUCT_IS_SAFE(header))
		return (ERROR_LOG("fat: header beyond binary"));
	nfat_arch = SWAP_ENDIAN_FORCE(header->nfat_arch);
	if (!SET(arch, header + sizeof(*header)))
		return (ERROR_LOG("fat: did not find arch within binary"));
	return (mach_fat_32_handle_format(nm_otool, arch, nfat_arch));
}
