#include "nm_otool.h"
#include "nm.h"

bool		elf_64_parse_section_header(t_nm_otool *nm_otool,
	Elf64_Shdr	*section_header, char *str_section)
{
	t_symbol *symbols;

	symbols = NULL;
	if ((section_header->sh_type == SHT_SYMTAB)
		|| (op(nm_otool, 'D')
				&& section_header->sh_type == SHT_DYNSYM))
	{
		if (!elf_64_set_symbols(nm_otool, section_header,
				str_section, &symbols))
			return (free_symbols(symbols));
	}
	display_symbols(nm_otool, symbols);
	free_symbols(symbols);
	return (true);
}
