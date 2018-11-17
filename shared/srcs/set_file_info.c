#include "nm_otool.h"

bool			set_file_info(t_nm_otool *nm_otool)
{
#ifdef __APPLE__
	return (set_mac_o_info(nm_otool));
#elif __linux__
	return (set_elf_info(nm_otool));
#else
	(void)nm_otool;
	return (false);
#endif
}
