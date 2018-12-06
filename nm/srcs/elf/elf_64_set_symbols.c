#include "nm_otool.h"
#include "nm.h"

static bool		elf_64_set_symbol(t_elf_symbols_info *info,
	Elf64_Sym *sym)
{
	if (!add_symbol(&info->symbols, sym->st_value,
			elf_get_symbol_type(info),
				info->str_section + sym->st_name))
		return (false);
	return (true);
}

bool					elf_64_set_symbols(t_nm_otool *nm_otool,
	Elf64_Shdr	*section_headers, t_elf_symbols_info *info)
{
	uint64_t		symbols_count;
	Elf64_Sym		*sym;

	symbols_count = section_headers[info->index].sh_size / sizeof(Elf64_Sym);
	if (!(SET(sym, nm_otool->file.memory
			+ section_headers[info->index].sh_offset)))
		return (ERROR_LOG("Not enough space for a symbol"));
	while (symbols_count--)
	{
		if (!STRUCT_IS_SAFE(sym))
			return (ERROR_LOG("Not enough space for a symbol"));
		if (!STRING_IS_SAFE(info->str_section + sym->st_name))
			return (ERROR_LOG("Symbol name outside string table"));
		if (!STRUCT_IS_SAFE(&section_headers[sym->st_shndx]))
			return (ERROR_LOG("Not enough space for symbol's section"));
		info->sh_flags = section_headers[sym->st_shndx].sh_flags;
		info->sh_type = section_headers[sym->st_shndx].sh_type;
		info->st_shndx = sym->st_shndx;
		info->st_info = sym->st_info;
		if (!elf_64_set_symbol(info, sym))
			return (ERROR_LOG("Failed when adding a symbol"));
		sym++;
	}
	return (true);
}
