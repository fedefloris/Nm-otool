#include "nm_otool.h"
#include "nm.h"

static void		set_symbol_info(t_nm_otool *nm_otool,
	Elf64_Sym *sym, Elf64_Shdr *section_header,
	t_elf_symbols_info *info)
{
	info->st_shndx = sym->st_shndx;
	info->st_info = sym->st_info;
	info->sh_flags = 0;
	info->sh_type = 0;
	if (sym->st_shndx != SHN_UNDEF
		&& STRUCT_IS_SAFE(section_header))
	{
		info->sh_flags = section_header->sh_flags;
		info->sh_type = section_header->sh_type;
	}
}

static bool		set_symbol(t_nm_otool *nm_otool,
	Elf64_Sym *sym, Elf64_Shdr *section_header,
	t_elf_symbols_info *info)
{
	set_symbol_info(nm_otool, sym, section_header, info);
	if (!add_symbol(&info->symbols, sym->st_value,
			elf_get_symbol_type(info),
				info->str_section + sym->st_name))
		return (false);
	return (true);
}

bool			elf_64_set_symbols(t_nm_otool *nm_otool,
	Elf64_Shdr *section_headers, t_elf_symbols_info *info)
{
	uint64_t		symbols_count;
	Elf64_Sym		*sym;

	symbols_count = section_headers[info->index].sh_size / sizeof(Elf64_Sym);
	if (!(SET(sym, nm_otool->file.memory
			+ section_headers[info->index].sh_offset)))
		return (ERROR_LOG("not enough space for a symbol"));
	while (symbols_count--)
	{
		if (!STRUCT_IS_SAFE(sym))
			return (ERROR_LOG("not enough space for a symbol"));
		if (!STRING_IS_SAFE(info->str_section + sym->st_name))
			return (ERROR_LOG("symbol name outside string table"));
		if (!set_symbol(nm_otool, sym,
				&section_headers[sym->st_shndx], info))
			return (ERROR_LOG("failed while adding a symbol"));
		sym++;
	}
	return (true);
}
