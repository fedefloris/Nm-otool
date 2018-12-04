#include "nm_otool.h"
#include "nm.h"

static bool	parse_section_header(t_nm_otool *nm_otool,
	Elf64_Shdr	*section_header, char *str_section)
{
	Elf64_Sym			*sym;
	uint64_t			symbols_count;
	unsigned char	bind;
	unsigned char	type;

	if ((section_header->sh_type == SHT_SYMTAB)
		|| (section_header->sh_type == SHT_DYNSYM)) // DYNSYM only if -D
	{
		sym = (Elf64_Sym*)(nm_otool->file.memory + section_header->sh_offset);
		symbols_count = section_header->sh_size / sizeof(Elf64_Sym);
		while (symbols_count--)
		{
			bind = ELF32_ST_BIND(sym->st_info);
			type = ELF32_ST_TYPE(sym->st_info);
			ft_printf("%016x ", sym->st_value);
			(void)bind;
			if (bind == STB_LOCAL && type == STT_FUNC)
				ft_putstr("t ");
			else if (bind == STB_GLOBAL && type == STT_FUNC)
				ft_putstr("T ");
			else if (type == STT_NOTYPE)
				ft_putstr("U ");
			ft_printf("%s\n", str_section + sym->st_name);
			sym++;
		}
	}
	return (true);
}

static bool	parse_section_headers(t_nm_otool *nm_otool,
	Elf64_Ehdr *header)
{
	Elf64_Shdr	*section_header;
	char				*str_section;
	uint16_t		i;

	if (!SET(section_header, (char*)header + header->e_shoff))
		return (false);
	i = 0;
	while (i < header->e_shnum)
	{
		if (!STRUCT_IS_SAFE(&section_header[i]))
			return (false);
		// Need to fix and protect it
		str_section = (char*)header + (&section_header[section_header->sh_link])->sh_offset;
		parse_section_header(nm_otool, section_header + i, str_section);
		i++;
	}
	return (true);
}

bool				elf_64_obj_handler(t_nm_otool *nm_otool)
{
	Elf64_Ehdr	*header;

	if (!SET(header, nm_otool->file.memory)
		|| !STRUCT_IS_SAFE(header))
		return (false);
	if (header->e_shoff <= sizeof(header))
		return (false); // Warning or Error?
	if (header->e_shnum == 0)
		return (false); // Warning or Error? (Also see man for SHN_LORESERVE)
	if (!parse_section_headers(nm_otool, header))
		return (false);
	return (true);
}
