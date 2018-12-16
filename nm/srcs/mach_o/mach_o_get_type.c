#include "nm_otool.h"
#include "nm.h"

static char			get_type_section(char type,
		uint8_t n_sect, uint8_t **sections)
{
	if (!ft_strcmp((char *)sections[n_sect], SECT_BSS))
		return ('B');
	if (!ft_strcmp((char *)sections[n_sect], SECT_DATA))
		return ('D');
	if (!ft_strcmp((char *)sections[n_sect], SECT_TEXT))
		return ('T');
	return (type);
}

char				mach_o_get_type(uint8_t n_type, uint64_t n_value,
		uint8_t n_sect, uint8_t **sections)
{
	char			type;

	type = '0';
	type = ((n_type & N_TYPE) == N_UNDF && n_value) ? 'C' : type;
	type = ((n_type & N_TYPE) == N_UNDF && !n_value) ? 'U' : type;
	type = ((n_type & N_TYPE) == N_ABS) ? 'A' : type;
	type = ((n_type & N_TYPE) == N_PBUD) ? 'U' : type;
	if ((n_type & N_TYPE) == N_SECT)
		type = get_type_section(type, n_sect, sections);
	type = ((n_type & N_TYPE) == N_INDR) ? 'I' : type;
	type = ((n_type & N_STAB) != 0) ? '-' : type;
	type += ((n_type & N_EXT) == 0 && type != '0' && type != '-') ? 32 : 0;
	return (type);
}
