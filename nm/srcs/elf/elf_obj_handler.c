#include "nm_otool.h"
#include "nm.h"

static bool	has_good_type(t_nm_otool *nm_otool)
{
	Elf32_Ehdr	*header;

	header = (Elf32_Ehdr*)nm_otool->file.memory;
	if (header->e_type != ET_REL
		&& header->e_type != ET_EXEC
		&& header->e_type != ET_DYN)
		return (ERROR_LOG("Type not supported"));
	return (true);
}

bool		elf_obj_handler(t_nm_otool *nm_otool)
{
	if (!has_good_type(nm_otool))
		return (false);
	if (nm_otool->file.format == ELF_32)
		return (elf_32_obj_handler(nm_otool));
	return (elf_64_obj_handler(nm_otool));
}
