#include "nm_otool.h"
#include "nm.h"

bool		obj_handler(t_nm_otool *nm_otool)
{
#ifdef __APPLE__
	if (nm_otool->file.format == MACH_O_32_FORMAT)
		return (mach_o_32_obj_handler(nm_otool));
	else if (nm_otool->file.format == MACH_O_64_FORMAT)
		return (mach_o_64_obj_handler(nm_otool));
#elif __linux__
	if (nm_otool->file.format == ELF_32_FORMAT)
		return (elf_32_obj_handler(nm_otool));
	else if (nm_otool->file.format == ELF_64_FORMAT)
		return (elf_32_obj_handler(nm_otool));
#endif
	return (false);
}
