#include "nm_otool.h"
#include "nm.h"

bool		elf_64_parse_section_headers(t_nm_otool *nm_otool,
	Elf64_Ehdr *header)
{
	Elf64_Shdr	*section_headers;
	char				*str_section;
	Elf64_Off		sh_offset;
	uint16_t		i;

	// Check if e_shnum is larger than or equal to SHN_LORESERVE (man elf)
	if (!SET(section_headers, (char*)header + header->e_shoff))
		return (ERROR_LOG("Not enough space for the first section header"));
	i = 0;
	while (i < header->e_shnum)
	{
		if (!STRUCT_IS_SAFE(&section_headers[i]))
			return (ERROR_LOG("Not enough space for an other section header"));
		if (!STRUCT_IS_SAFE(&section_headers[section_headers[i].sh_link]))
			return (ERROR_LOG("sh_link index is outside the section headers array"));
		sh_offset = section_headers[section_headers[i].sh_link].sh_offset;
		if (!SET(str_section, (char*)header + sh_offset))
			return (ERROR_LOG("Not enough space for the string table"));
		if (!elf_64_parse_section_header(nm_otool, &section_headers[i], str_section))
			return (false); // free symbols
		i++;
	}
	return (true);
}
