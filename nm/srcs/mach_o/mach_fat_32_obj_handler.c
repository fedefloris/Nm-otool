#include "nm_otool.h"
#include "nm.h"

void	 swap_64(unsigned char word)
{
	unsigned char	tmp;
	unsigned char	new_word;
	int				i;

	i = 0;
	while (i < 4)
	{
		tmp = word & 3;
		new_word = new_word << 2;
		new_word |= tmp;
		word = word >> 2;
		i++;
	}
	//ft_printf("------->value = %.2x\n", y);
}

uint32_t    swap_endian(uint32_t value)
{
	uint32_t    result;
	uint32_t    byte1;
	uint32_t    byte2;
	uint32_t    byte3;
	uint32_t    byte4;

	byte1 = (value & 0xFF) << 24;
	byte2 = (value & 0xFF00) << 8;
	byte3 = (value & 0xFF0000) >> 8;
	byte4 = (value & 0xFF000000) >> 24;
	result = byte1 | byte2 | byte3 | byte4;
	return (result);
}

static bool			mach_fat_32_launch_mach_o(t_nm_otool *nm_otool, struct fat_arch *arch, uint32_t nfat_arch, bool (*mach_o_function)(t_nm_otool *))
{
	bool			status;
	t_file			file_data;

	status = false;
	file_data = nm_otool->file;
	while (nfat_arch--)
	{
		if (!STRUCT_IS_SAFE(arch))
			return (ERROR_LOG("fat: arch beyond binary"));
		ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
		nm_otool->file.name = file_data.name;
		nm_otool->file.size = arch->size;
		nm_otool->file.memory = file_data.memory + swap_endian(arch->offset);
		if ((nm_otool->file.end_of_file = file_data.memory + file_data.size - 1) > file_data.end_of_file)//Check if safe
			return (ERROR_LOG("fat: arch->size bad size."));
		nm_otool->file.endianness = file_data.endianness;
		if (mach_o_function(nm_otool))
			status = true;
		if (!(NEXT_STRUCT(arch)))
			return (ERROR_LOG("fat: next arch beyond binary"));
	}
	nm_otool->file = file_data;
	return (status);
}

static bool			mach_fat_32_handle_format(t_nm_otool *nm_otool, struct fat_arch *arch, uint32_t nfat_arch)
{
	if (!STRUCT_IS_SAFE(arch))
		return (ERROR_LOG("fat: arch beyond binary"));
	if (swap_endian(arch->cputype) == CPU_TYPE_X86_64)
		return (mach_fat_32_launch_mach_o(nm_otool, arch, nfat_arch, &mach_o_64_obj_handler));
	else if (swap_endian(arch->cputype) == CPU_TYPE_I386)
		return (mach_fat_32_launch_mach_o(nm_otool, arch, nfat_arch, &mach_o_32_obj_handler));
	return (ERROR_LOG("fat: bad arch->cputype"));
}

bool				mach_fat_32_obj_handler(t_nm_otool *nm_otool)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	uint32_t			nfat_arch;

	if (!SET(header, nm_otool->file.memory))
		return (ERROR_LOG("fat: header beyond binary"));
	if (!STRUCT_IS_SAFE(header))
		return (ERROR_LOG("fat: header beyond binary"));
	nfat_arch = swap_endian(header->nfat_arch);
	if (!SET(arch, header + sizeof(*header)))
		return (ERROR_LOG("fat: did not find arch within binary"));
	return (mach_fat_32_handle_format(nm_otool, arch, nfat_arch));
}
