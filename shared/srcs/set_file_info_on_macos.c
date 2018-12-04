#include "nm_otool.h"
#include <mach-o/loader.h>
#include <stdint.h>

static bool	set_mach_o_format(t_nm_otool *nm_otool, uint32_t magic_number)
{
	if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		nm_otool->file.format = MACH_O_32_FORMAT;
	else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		nm_otool->file.format = MACH_O_64_FORMAT;
	else
		return (false);
	nm_otool->file.endianness = LITTLE_ENDIAN_TYPE;
	if (magic_number == MH_CIGAM || magic_number == MH_CIGAM_64)
		nm_otool->file.endianness = BIG_ENDIAN_TYPE;
	return (true);
}

static bool	set_fat_format(t_nm_otool *nm_otool, uint32_t magic_number)
{
	if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		nm_otool->file.format = MACH_O_FAT_32;
	else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64)
		nm_otool->file.format = MACH_O_FAT_64;
	else
		return (false);
	nm_otool->file.endianness = LITTLE_ENDIAN_TYPE;
	if (magic_number == FAT_CIGAM || magic_number == FAT_CIGAM_64)
		nm_otool->file.endianness = BIG_ENDIAN_TYPE;
	return (true);
}

static bool	set_format(t_nm_otool *nm_otool)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm_otool->file.memory;
	if (!set_mach_o_format(nm_otool, magic_number)
		&& !set_fat_format(nm_otool, magic_number))
		return (ERROR_LOG("Bad magic number"));
	if (nm_otool->file.format == MACH_O_64_FORMAT
		&& nm_otool->file.size < (long)sizeof(struct mach_header_64))
		return (ERROR_LOG("Bad size"));
	return (true);
}

bool		set_file_info_on_macos(t_nm_otool *nm_otool)
{
	if (nm_otool->file.size < (long)sizeof(struct mach_header))
		return (ERROR_LOG("Bad size"));
	else if (!set_format(nm_otool))
		return (false);
	return (true);
}
