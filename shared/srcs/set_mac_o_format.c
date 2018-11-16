#include "nm_otool.h"
#include <mach-o/loader.h>
#include <stdint.h>

bool			set_mac_o_format(t_file *file)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)file->memory;
	if (magic_number == MH_MAGIC)
		file->format = MAC_O_32_FORMAT;
	else if (magic_number == MH_MAGIC_64)
		file->format = MAC_O_64_FORMAT;
	else
		return (false);
	return (true);
}
