#include "nm_otool.h"
#include "nm.h"

static bool	has_good_type(t_nm_otool *nm_otool)
{
	uint16_t	type;

	type = SWAP_ENDIAN(((Elf32_Ehdr*)nm_otool->file.memory)->e_type);
	return (type == ET_REL || type == ET_EXEC || type == ET_DYN);
}

bool		elf_obj_handler(t_nm_otool *nm_otool)
{
	if (!has_good_type(nm_otool))
		return (ERROR_LOG("type not supported"));
	if (IS_ELF_32(nm_otool->file.format))
		return (elf_obj_handler_32(nm_otool));
	else if (IS_ELF_64(nm_otool->file.format))
		return (elf_obj_handler_64(nm_otool));
	return (ERROR_LOG("unrecognized format"));
}
