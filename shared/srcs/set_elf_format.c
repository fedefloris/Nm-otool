#include "nm_otool.h"

bool			set_elf_format(t_file *file)
{
	Elf32_Ehdr	*header;

	header = (Elf32_Ehdr*)file->memory;
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
			header->e_ident[EI_MAG1] != ELFMAG1 ||
			header->e_ident[EI_MAG2] != ELFMAG2 ||
			header->e_ident[EI_MAG3] != ELFMAG3)
		return (false);
	file->format = ELF_FORMAT;
	return (true);
}
