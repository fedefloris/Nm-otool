#include "nm_otool.h"

bool			set_file_format(t_nm_otool *nm_otool)
{
#ifdef __APPLE__
	return (set_mac_o_format(nm_otool));
#elif __linux__
	return (set_elf_format(nm_otool));
#else
	(void)nm_otool;
	return (false);
#endif
}
