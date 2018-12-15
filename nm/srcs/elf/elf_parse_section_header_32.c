#include "nm_otool.h"
#include "nm.h"

bool		elf_parse_section_header_32(t_nm_otool *nm_otool,
	Elf32_Shdr *section_headers,
	t_elf_symbols_info *info)
{
	Elf32_Word	sh_type;

	sh_type = SWAP_ENDIAN(section_headers[info->index].sh_type);
	if ((!op(nm_otool, 'D') && sh_type == SHT_SYMTAB)
		|| (op(nm_otool, 'D') && sh_type == SHT_DYNSYM))
	{
		if (!elf_set_symbols_32(nm_otool, section_headers, info))
			return (free_symbols(info->symbols));
		sort_symbols(nm_otool, &info->symbols);
		display_symbols(nm_otool, info->symbols);
		free_symbols(info->symbols);
	}
	return (true);
}
