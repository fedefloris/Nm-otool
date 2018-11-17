#include "nm_otool.h"
#include <mach-o/loader.h>
#include <stdint.h>

bool			set_mach_o_info(t_nm_otool *nm_otool)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm_otool->file.memory;
	if (magic_number == MH_MAGIC)
		nm_otool->file.format = MACH_O_32_FORMAT;
	else if (magic_number == MH_MAGIC_64)
		nm_otool->file.format = MACH_O_64_FORMAT;
	else
		return (false);
	return (true);
}
