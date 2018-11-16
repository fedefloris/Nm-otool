#include "nm_otool.h"
#include "ft_printf.h"
#include <stdint.h>

#ifdef __APPLE__
bool			set_mac_o_format(t_file *file)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)file->memory;
	if (magic_number == MH_MAGIC)
		file->format = MAC_O_32_FORMAT;
	else if (magic_number == MH_MAGIC_64)
		file->format = MAC_O_64_FORMAT;
	else
		return (false);
	return (true);
}
#elif __linux__
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
#endif

bool			set_file_format(t_file *file)
{
#ifdef __APPLE__
	return (set_mac_o_format(file));
#elif __linux__
	return (set_elf_format(file));
#else
	(void)file;
	return (false);
#endif
}
