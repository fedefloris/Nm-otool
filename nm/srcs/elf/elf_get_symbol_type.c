#include "nm_otool.h"
#include "nm.h"

char		elf_get_symbol_type(unsigned char st_info)
{
	unsigned char	bind;
	unsigned char	type;

	bind = ELF32_ST_BIND(st_info);
	type = ELF32_ST_TYPE(st_info);
	if (bind == STB_LOCAL && type == STT_FUNC)
		;// ft_putstr("t ");
	else if (bind == STB_GLOBAL && type == STT_FUNC)
		;// ft_putstr("T ");
	else if (type == STT_NOTYPE)
		;	// ft_putstr("U ");
	return ('U');
}
