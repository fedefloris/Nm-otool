#include "nm_otool.h"
#include "nm.h"

bool	elf_64_set_symbols(t_nm_otool *nm_otool, Elf64_Shdr	*section_header,
	char *str_section, t_symbol **symbols)
{
	uint64_t		symbols_count;
	Elf64_Sym		*sym;

	symbols_count = section_header->sh_size / sizeof(Elf64_Sym);
	if (!(SET(sym, nm_otool->file.memory + section_header->sh_offset)))
		return (ERROR_LOG("Not enough space for a symbol"));
	while (symbols_count--)
	{
		if (!STRUCT_IS_SAFE(sym))
			return (ERROR_LOG("Not enough space for a symbol"));
		if (!STRING_IS_SAFE(str_section + sym->st_name))
			return (ERROR_LOG("Symbol name outside string table"));
		if (!add_symbol(symbols, sym->st_value,
				elf_get_symbol_type(sym->st_info), str_section + sym->st_name))
			return (ERROR_LOG("Malloc call failed when adding a symbol"));
		sym++;
	}
	return (true);
}
