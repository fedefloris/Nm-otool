#include "nm_otool.h"
#include "nm.h"

bool		elf_32_obj_handler(t_nm_otool *nm_otool)
{
	// Elf32_Shdr	*str_section;
	Elf32_Shdr	*section;
	Elf32_Ehdr	*header;
	uint16_t		i;

	i = 0;
	header = (Elf32_Ehdr*)nm_otool->file.memory;
	ft_printf("Elf32, File_name: %s\n", nm_otool->file.name);
	ft_printf("Section header offset: %lu\n", header->e_shoff);
	section = (Elf32_Shdr*)((char*)nm_otool->file.memory + header->e_shoff);
	// str_section = (Elf32_Shdr*)((char*)nm_otool->file.memory +
	// (header->e_shoff + (header->e_shstrndx * sizeof(*section))));
	while (i < header->e_shnum)
	{
		section = (Elf32_Shdr*)((char*)section + sizeof(*section));
		if ((section->sh_type == SHT_SYMTAB)
			|| (section->sh_type == SHT_DYNSYM))
		{
			ft_printf("Section n. %u is a Symbolic table\n", i);
		}
		i++;
	}
	return (true);
}
