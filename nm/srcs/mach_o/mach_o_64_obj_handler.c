#include "nm_otool.h"
#include "nm.h"

static char			get_type_64(uint8_t n_type, u_int64_t n_value, u_int8_t n_sect, t_section sections)
{
	char			type;

	type = '0';
	if ((n_type & N_TYPE) == N_UNDF)
		type = (n_value) ? 'C' :'U';
	else if ((n_type & N_TYPE) == N_ABS)
		type = 'A';
	else if ((n_type & N_TYPE) == N_PBUD)
		type = 'U';
	else if ((n_type & N_TYPE) == N_SECT)
	{
		ft_printf("Sect %d, Bss %d, data %d, text %d\n", n_sect, sections.bss, sections.data, sections.text);
		type = (n_sect == sections.bss) ? 'B' : type;
		type = (n_sect == sections.data) ? 'D' : type;
		type = (n_sect == sections.text) ? 'T' : type;
		type = (type == '0') ? 'S' : type;
	}
	else if ((n_type & N_TYPE) == N_INDR)
		type = 'I';
	if ((n_type & N_STAB) != 0)
		type = 'Z';
	if ((n_type & N_EXT) == 0 && type != '0')
		type += 32;
	return (type);
}

static bool			get_symbols_64(t_nm_otool *nm_otool, struct symtab_command *symtab, t_section sections)
{
	uint32_t		i;
	char			*str;
	char			*stringtable;
	struct nlist_64	*array;

	i = 0;
	if (!(array = (struct nlist_64 *)get_safe_address(nm_otool, (char *)nm_otool->file.memory + symtab->symoff)))
		return (false);
	if (!(stringtable = (char *)get_safe_address(nm_otool, (char *)nm_otool->file.memory + symtab->stroff)))
		return (false);
	while (i < symtab->nsyms)
	{
		if (!get_safe_address(nm_otool, (char *)array + sizeof(*array)))
			return (false);
		if (!(str = (char *)get_safe_address(nm_otool, (char *)stringtable + array[i].n_un.n_strx)))
			return (false);
		if (!string_is_safe(nm_otool, (char *)str))
			return (false);
		ft_printf("%16.16x ", array[i].n_value);
		ft_printf("%c (%u) ", get_type_64(array[i].n_type, array[i].n_value, array[i].n_sect, sections), array[i].n_sect);
		ft_printf("%s\n", str);
		i++;
	}
	return (true);
}

static bool			get_sections_64(t_nm_otool *nm_otool, t_section *sections, struct segment_command_64 *segment)//maybe does not have to be 64 only.
{
	uint32_t				i;
	static unsigned char	sec_number = 1;
	struct section_64		*sec;

	i = 0;
	if (!(sec = (struct section_64 *)get_safe_address(nm_otool, (char *)segment + sizeof(*segment))))
		return (false);
	while (i++ < segment->nsects)
	{
		if (!get_safe_address(nm_otool, (char *)sec + sizeof(*sec)))
			return (false);
		if (!string_is_safe(nm_otool, (char *)sec->sectname))
			return (false);
		if (!ft_strcmp(sec->sectname, SECT_DATA))
			sections->data = sec_number;
		else if (!ft_strcmp(sec->sectname, SECT_BSS))
			sections->bss = sec_number;
		else if (!ft_strcmp(sec->sectname, SECT_TEXT))
			sections->text = sec_number;
		sec_number++;
	}	
	return (true);
}

bool				mach_o_64_obj_handler(t_nm_otool *nm_otool)
{
	uint32_t				i;//maybe remove
	struct mach_header_64	*header;
	t_lc					*lc;
	struct symtab_command	*symtab;
	t_section				sections;

	i = 0;
	symtab = NULL;
	if (!(header = (struct mach_header_64 *)get_safe_address(nm_otool, (char *)nm_otool->file.memory)))
		return (false);
	if (!(lc = (t_lc *)get_safe_address(nm_otool, (char *)nm_otool->file.memory + sizeof(*header))))
		return (false);
	if (!get_safe_address(nm_otool, (char *)header + sizeof(*header)))
		return (false);
	while (i++ < header->ncmds)
	{
		if (!get_safe_address(nm_otool, (char *)lc + sizeof(*lc)))
			return (false);
		if (!symtab && lc->cmd == LC_SYMTAB)
		{
			if (!(symtab = (struct symtab_command *)get_safe_address(nm_otool, (char *)lc))
				|| !get_safe_address(nm_otool, (char *)lc + sizeof(*symtab)))
				return (false);
		}
		if (lc->cmd == LC_SEGMENT_64)
			get_sections_64(nm_otool, &sections, (struct segment_command_64 *)lc);
		if (lc->cmdsize <= sizeof(*lc))
			return (false);
		if (!(lc = (t_lc *)get_safe_address(nm_otool, (char *)lc + lc->cmdsize)))
			return (false);
	}
	if (symtab)
		return (get_symbols_64(nm_otool, symtab, sections));
	return (true);
}
