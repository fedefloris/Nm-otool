#include "nm_otool.h"
#include "nm.h"

bool				elf_64_obj_handler(t_nm_otool *nm_otool)
{
	Elf64_Ehdr	*header;

	if (!SET(header, nm_otool->file.memory)
		|| !STRUCT_IS_SAFE(header))
			return (ERROR_LOG("Not enough space for the ELF header"));
	if (header->e_shoff == 0)
		return (true);
	return (elf_64_parse_section_headers(nm_otool, header));
}
