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
		nm_otool->file.format = ELF_32;
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		nm_otool->file.format = ELF_64;
	else
		return (false);
	return (true);
}

static bool	has_good_version(Elf32_Ehdr *header)
{
	return (header->e_ident[EI_VERSION] == EV_CURRENT
		&& header->e_version == EV_CURRENT);
}

bool				set_file_info_on_linux(t_nm_otool *nm_otool)
{
	Elf32_Ehdr	*header;

	if (!SET(header, nm_otool->file.memory) || !STRUCT_IS_SAFE(header))
		return (ERROR_LOG("Bad size"));
	else if (!has_good_ELF_magic_number(header))
		return (ERROR_LOG("Bad magic number"));
	else if (!has_good_version(header))
		return (ERROR_LOG("Wrong version"));
	else if (!set_format(nm_otool, header))
		return (ERROR_LOG("Architecture not supported"));
	else if (IS_ELF_64(nm_otool->file.format)
		&& nm_otool->file.size < (long)sizeof(Elf64_Ehdr))
		return (ERROR_LOG("Bad size"));
	else if (!set_endianness(nm_otool, header))
		return (ERROR_LOG("Bad endianness"));
	return (true);
}
