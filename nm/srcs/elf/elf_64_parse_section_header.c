#include "nm_otool.h"
#include "nm.h"

bool		elf_64_parse_section_header(t_nm_otool *nm_otool,
	Elf64_Shdr	*section_header, char *str_section)
{
	if ((section_header->sh_type == SHT_SYMTAB)
		|| (section_header->sh_type == SHT_DYNSYM)) // DYNSYM only if -D
		return (elf_64_get_symbols(nm_otool, section_header, str_section));
	return (true);
}
