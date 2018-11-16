#include "nm_otool.h"

bool			set_file_format(t_file *file)
{
#ifdef __APPLE__
	return (set_mac_o_format(file));
#elif __linux__
	return (set_elf_format(file));
#else
	(void)file;
	return (false);
#endif
}
