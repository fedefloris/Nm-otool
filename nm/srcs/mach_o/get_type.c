#include "nm_otool.h"
#include "nm.h"

static char			get_type_section(char type,
		u_int8_t n_sect, t_section *sections)
{
	while (sections)
	{
		if (n_sect == sections->sec_number)
			break ;
		sections = sections->next;
	}
	if (!sections)
		type = 'S';
	else
	{
		type = (!ft_strcmp(sections->name, SECT_BSS)) ? 'B' : type;
		type = (!ft_strcmp(sections->name, SECT_DATA)) ? 'D' : type;
		type = (!ft_strcmp(sections->name, SECT_TEXT)) ? 'T' : type;
	}
	return (type);
}

char				get_type(uint8_t n_type, u_int64_t n_value,
		u_int8_t n_sect, t_section *sections)
{
	char			type;

	type = '0';
	type = ((n_type & N_TYPE) == N_UNDF && n_value) ? 'C' : type;
	type = ((n_type & N_TYPE) == N_UNDF && !n_value) ? 'U' : type;
	type = ((n_type & N_TYPE) == N_ABS && !n_value) ? 'A' : type;
	type = ((n_type & N_TYPE) == N_PBUD && !n_value) ? 'U' : type;
	if ((n_type & N_TYPE) == N_SECT)
	{
		type = get_type_section(type, n_sect, sections);
	}
	type = ((n_type & N_TYPE) == N_INDR && !n_value) ? 'I' : type;
	type = ((n_type & N_STAB) != 0) ? '-' : type;
	type += ((n_type & N_EXT) == 0 && type != '0' && type != '-') ? 32 : 0;
	return (type);
}
