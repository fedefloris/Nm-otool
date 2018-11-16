#include "nm_otool.h"
#include "ft_printf.h"
#include <stdint.h>

bool				set_file_format(t_nm_otool *nm_otool)
{
#ifdef __APPLE__
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm_otool->file.->memory;
	if (magic_number == MH_MAGIC)
		nm_otool->file.->format = BITS_32;
	else if (magic_number == MH_MAGIC_64)
		nm_otool->file.->format = BITS_64;
	else
		return (false);
	return (true);
#else
	(void)nm_otool->file.;
	return (false);
#endif
}
