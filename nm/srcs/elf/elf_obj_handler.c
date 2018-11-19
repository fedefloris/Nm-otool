#include "nm_otool.h"
#include "nm.h"

bool		elf_obj_handler(t_nm_otool *nm_otool)
{
	if (nm_otool->file.format == ELF_32_FORMAT)
		return (elf_32_obj_handler(nm_otool));
	return (elf_64_obj_handler(nm_otool));
}
