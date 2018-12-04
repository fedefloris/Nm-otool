#include "nm_otool.h"

static bool	set_endianness(t_nm_otool *nm_otool, Elf32_Ehdr *header)
{
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		nm_otool->file.endianness = LITTLE_ENDIAN_TYPE;
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		nm_otool->file.endianness = BIG_ENDIAN_TYPE;
	else
		return (false);
	return (true);
}

static bool	set_format(t_nm_otool *nm_otool, Elf32_Ehdr *header)
{
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		nm_otool->file.format = ELF_32_FORMAT;
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
	{
		nm_otool->file.format = ELF_64_FORMAT;
		if (nm_otool->file.size <
				(long)sizeof(*(Elf64_Ehdr*)nm_otool->file.memory))
				return (ERROR_LOG("Bad size"));
	}
	else
		return (ERROR_LOG("Architecture not supported"));
	return (true);
}

static bool	has_good_version(Elf32_Ehdr *header)
{
	return (header->e_ident[EI_VERSION] == EV_CURRENT
		&& header->e_version == EV_CURRENT);
}

static bool	has_good_magic_number(Elf32_Ehdr *header)
{
	return (header->e_ident[EI_MAG0] == ELFMAG0
		&& header->e_ident[EI_MAG1] == ELFMAG1
		&& header->e_ident[EI_MAG2] == ELFMAG2
		&& header->e_ident[EI_MAG3] == ELFMAG3);
}

bool				set_file_info_on_linux(t_nm_otool *nm_otool)
{
	Elf32_Ehdr	*header;

	header = (Elf32_Ehdr*)nm_otool->file.memory;
	if (nm_otool->file.size < (long)sizeof(*header))
		return (ERROR_LOG("Bad size"));
	else if (!has_good_magic_number(header))
		return (ERROR_LOG("Bad magic number"));
	else if (!has_good_version(header))
		return (ERROR_LOG("Wrong version"));
	else if (!set_format(nm_otool, header))
		return (false);
	else if (!set_endianness(nm_otool, header))
		return (ERROR_LOG("Bad endianness"));
	return (true);
}
