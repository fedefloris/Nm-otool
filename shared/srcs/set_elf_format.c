#include "nm_otool.h"
#include <elf.h>

static bool	has_good_magic_number(Elf32_Ehdr	*header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
			header->e_ident[EI_MAG1] != ELFMAG1 ||
			header->e_ident[EI_MAG2] != ELFMAG2 ||
			header->e_ident[EI_MAG3] != ELFMAG3)
		return (false);
	return (true);
}

static bool	set_format(t_nm_otool *nm_otool, Elf32_Ehdr	*header)
{
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		nm_otool->file.format = ELF_32_FORMAT;
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		nm_otool->file.format = ELF_64_FORMAT;
	else
		return (false);
	return (true);
}

bool				set_elf_format(t_nm_otool *nm_otool)
{
	Elf32_Ehdr	*header;

	header = (Elf32_Ehdr*)nm_otool->file.memory;
	if (!has_good_magic_number(header))
		return (false);
	if (!set_format(nm_otool, header))
		return (false);
	return (true);
}
