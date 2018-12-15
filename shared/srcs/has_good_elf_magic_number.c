#include "nm_otool.h"

bool		has_good_elf_magic_number(Elf32_Ehdr *header)
{
	return (header->e_ident[EI_MAG0] == ELFMAG0
		&& header->e_ident[EI_MAG1] == ELFMAG1
		&& header->e_ident[EI_MAG2] == ELFMAG2
		&& header->e_ident[EI_MAG3] == ELFMAG3);
}
