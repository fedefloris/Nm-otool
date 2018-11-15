#include "nm_otool.h"
#include "ft_printf.h"
#include <stdint.h>

bool				set_file_format(t_file *file)
{
#ifdef __APPLE__
	uint32_t		magic_number;

	magic_number = *(uint32_t *)file->memory;
	if (magic_number == MH_MAGIC)
		file->format = BITS_32;
	else if (magic_number == MH_MAGIC_64)
		file->format = BITS_64;
	else
		return (false);
	return (true);
#else
	(void)file;
	return (false);
#endif
}
