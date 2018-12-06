#include "nm_otool.h"
#include "nm.h"

char		elf_get_symbol_type(t_elf_symbol_info	*info)
{
	unsigned char	st_bind;
	unsigned char	st_type;
	char					type;

	st_bind = ELF32_ST_BIND(info->symbol_info);
	st_type = ELF32_ST_TYPE(info->symbol_info);
	type = 'U';
	// if (st_type == STT_NOTYPE)
	// 	type = 'U';
	if (info->section_index == SHN_ABS)
    type = 'A';
	// else if (section[sym->st_shndx].sh_type == SHT_NOBITS)
    // type = 'B';
	// else if (sym->st_shndx == SHN_COMMON)
    // type = 'C';
	// else if (section[sym->st_shndx].sh_type == SHT_PROGBITS)
    // type = 'D';
	// else if ()
    // type = 'G';
	// else if ()
    // type = 'i';
	// else if ()
    // type = 'I';
	// else if ()
    // type = 'N';
	if (st_bind == STB_LOCAL)
		type += 32;
	return (type);
}
