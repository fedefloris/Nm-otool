#include "nm_otool.h"
#include "nm.h"
#include <elf.h>

bool		elf_64_obj_handler(t_nm_otool *nm_otool)
{
	// Elf64_Shdr	*str_section;
	Elf64_Shdr	*section;
	Elf64_Ehdr	*header;
	uint16_t		i;

	i = 0;
	header = (Elf64_Ehdr*)nm_otool->file.memory;
	ft_printf("Elf64, File_name: %s\n", nm_otool->file.name);
	ft_printf("Section header offset: %lu\n", header->e_shoff);
	section = (Elf64_Shdr*)((char*)nm_otool->file.memory + header->e_shoff);
	// str_section = (Elf64_Shdr*)((char*)nm_otool->file.memory +
	// (header->e_shoff + (header->e_shstrndx * sizeof(*section))));
	while (i < header->e_shnum)
	{
		section = (Elf64_Shdr*)((char*)section + sizeof(*section));
		if ((section->sh_type == SHT_SYMTAB)
			|| (section->sh_type == SHT_DYNSYM))
		{
			ft_printf("Section n. %u is a Symbolic table\n", i);
		}
		i++;
	}
	return (true);
}
