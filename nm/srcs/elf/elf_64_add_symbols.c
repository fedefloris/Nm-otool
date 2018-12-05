#include "nm_otool.h"
#include "nm.h"

bool		elf_64_add_symbols(t_nm_otool *nm_otool,
	Elf64_Shdr	*section_header, char *str_section)
{
	Elf64_Sym			*sym;
	uint64_t			symbols_count;
	unsigned char	bind;
	unsigned char	type;

	if (!(SET(sym, nm_otool->file.memory + section_header->sh_offset)))
		return (ERROR_LOG("Not enough space for a symbol"));
	symbols_count = section_header->sh_size / sizeof(Elf64_Sym);
	while (symbols_count--)
	{
		if (!(STRUCT_IS_SAFE(sym)))
			return (ERROR_LOG("Not enough space for a symbol"));
		bind = ELF32_ST_BIND(sym->st_info);
		type = ELF32_ST_TYPE(sym->st_info);
		ft_printf("%016x ", sym->st_value);
		if (bind == STB_LOCAL && type == STT_FUNC)
			ft_putstr("t ");
		else if (bind == STB_GLOBAL && type == STT_FUNC)
			ft_putstr("T ");
		else if (type == STT_NOTYPE)
			ft_putstr("U ");
		ft_printf("%s\n", str_section + sym->st_name);
		sym++;
	}
	return (true);
}
