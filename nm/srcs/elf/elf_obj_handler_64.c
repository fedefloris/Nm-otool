#include "nm_otool.h"
#include "nm.h"

bool		elf_obj_handler_64(t_nm_otool *nm_otool)
{
	Elf64_Ehdr	*header;

	if (!SET(header, nm_otool->file.memory)
		|| !STRUCT_IS_SAFE(header))
			return (ERROR_LOG("not enough space for the ELF header"));
	if (header->e_shoff == 0)
		return (true);
	return (elf_parse_section_headers_64(nm_otool, header));
}
