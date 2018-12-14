#include "nm_otool.h"
#include "nm.h"

char	elf_get_symbol_type(t_elf_symbols_info *info)
{
	unsigned char	st_bind;
	char			type;

	st_bind = ELF32_ST_BIND(info->st_info);
	if (info->st_shndx == SHN_ABS)
		return (st_bind == STB_LOCAL ? 'a' : 'A');
	if (info->st_shndx == SHN_UNDEF)
		return ('U');
	type = "NDTSFBD         "[ELF32_ST_TYPE(info->st_info)];
	if (type == 'D')
	{
		if (st_bind == STB_GNU_UNIQUE)
			type = 'u';
		else if ((info->sh_flags & SHF_WRITE) == 0)
			type = 'R';
		else if (info->sh_type == SHT_NOBITS)
			type = 'B';
	}
	return (st_bind == STB_LOCAL ? ft_tolower(type) : type);
}
