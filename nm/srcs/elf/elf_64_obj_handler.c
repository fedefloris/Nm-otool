#include "nm_otool.h"
#include "nm.h"

bool				elf_64_obj_handler(t_nm_otool *nm_otool)
{
	char				*str_section;
	Elf64_Shdr	*section;
	Elf64_Ehdr	*header;
	Elf64_Sym		*sym;
	uint64_t		symbols_count;
	uint16_t		i;
	unsigned char	bind;
	unsigned char	type;

	i = 0;
	header = (Elf64_Ehdr*)nm_otool->file.memory;
	section = (Elf64_Shdr*)((char*)nm_otool->file.memory + header->e_shoff);
	while (i < header->e_shnum)
	{
		if ((section[i].sh_type == SHT_SYMTAB)
			|| (section[i].sh_type == SHT_DYNSYM))
		{
			sym = (Elf64_Sym*)(((char*)nm_otool->file.memory) + section[i].sh_offset);
			str_section = (char*)nm_otool->file.memory + section[section[i].sh_link].sh_offset;
			symbols_count = section[i].sh_size / sizeof(Elf64_Sym);
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
		i++;
	}
	return (true);
}
