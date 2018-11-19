#include "nm_otool.h"
#include <mach-o/loader.h>
#include <stdint.h>

static void	set_64_format(t_nm_otool *nm_otool, uint32_t magic_number)
{
	nm_otool->file.format = MACH_O_64_FORMAT;
	nm_otool->file.endianness = LITTLE_ENDIAN_TYPE;
	if (magic_number == MH_CIGAM_64)
		nm_otool->file.endianness = BIG_ENDIAN_TYPE;
}

static void	set_32_format(t_nm_otool *nm_otool, uint32_t magic_number)
{
	nm_otool->file.format = MACH_O_32_FORMAT;
	nm_otool->file.endianness = LITTLE_ENDIAN_TYPE;
	if (magic_number == MH_CIGAM)
		nm_otool->file.endianness = BIG_ENDIAN_TYPE;
}

static bool	set_format(t_nm_otool *nm_otool)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm_otool->file.memory;
	if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		set_32_format(nm_otool, magic_number);
	else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		set_64_format(nm_otool, magic_number);
		if (nm_otool->file.size < (long)sizeof(struct mach_header_64))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool		set_mach_o_info(t_nm_otool *nm_otool)
{
	if (nm_otool->file.size < (long)sizeof(struct mach_header))
		ERROR_LOG("Bad size");
	else if (!set_format(nm_otool))
		ERROR_LOG("Bad magic number");
	else
		return (true);
	return (false);
}
