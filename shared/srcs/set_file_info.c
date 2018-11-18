#include "nm_otool.h"
#include "ft_printf.h"

bool			set_file_info(t_nm_otool *nm_otool)
{
#ifdef __APPLE__
	return (set_mach_o_info(nm_otool));
#elif __linux__
	return (set_elf_info(nm_otool));
#else
	ft_printf("%s OS not supported\n", ERROR_HEADER);
	return (false);
#endif
}
