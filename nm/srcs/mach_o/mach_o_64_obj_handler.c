#include "nm_otool.h"
#include "nm.h"

static bool			get_symbols_64(t_nm_otool *nm_otool,
		struct symtab_command *symtab, t_section *sections)
{
	uint32_t		i;
	char			*str;
	char			*stringtable;
	struct nlist_64	*array;
	t_symbol		*symbols;

	i = 0;
	symbols = NULL;
	if (!(array = (struct nlist_64 *)get_safe_address(nm_otool, (char *)nm_otool->file.memory + symtab->symoff)))
		return (free_symbols(symbols));
	if (!(stringtable = (char *)get_safe_address(nm_otool, (char *)nm_otool->file.memory + symtab->stroff)))
		return (free_symbols(symbols));
	while (i < symtab->nsyms)
	{
		if (!get_safe_address(nm_otool, (char *)array + sizeof(*array)))
			return (free_symbols(symbols));
		if (!(str = (char *)get_safe_address(nm_otool, (char *)stringtable + array[i].n_un.n_strx)))
			return (free_symbols(symbols));
		if (!string_is_safe(nm_otool, (char *)str))
			return (free_symbols(symbols));
		if ((array[i].n_type & N_STAB) == 0)
		{
			if (!(add_symbol(&symbols, array[i].n_value,
				get_type(array[i].n_type, array[i].n_value, array[i].n_sect, sections), str)))
				return (free_symbols(symbols));
		}
		i++;
	}
	display_symbols(nm_otool, symbols);
	free_sections(sections);
	free_symbols(symbols);
	return (true);
}

static bool			get_sections_64(t_nm_otool *nm_otool,
		t_section **sections, struct segment_command_64 *segment)//maybe does not have to be 64 only.
{
	uint32_t				i;
	static unsigned char	sec_number = 1;
	struct section_64		*sec;
	t_section				*new;

	i = 0;
	if (!(sec = (struct section_64 *)get_safe_address(nm_otool, (char *)segment + sizeof(*segment))))
		return (false);
	while (i++ < segment->nsects)
	{
		if (!get_safe_address(nm_otool, (char *)sec + sizeof(*sec)))
			return (false);
		if (!string_is_safe(nm_otool, (char *)sec->sectname))
			return (false);
		if (!ft_strcmp(sec->sectname, SECT_DATA)
			|| !ft_strcmp(sec->sectname, SECT_BSS)
			|| !ft_strcmp(sec->sectname, SECT_TEXT))
		{
			if (!(new = (t_section *)ft_memalloc(sizeof(t_section))))
				return (false);
			new->name = sec->sectname;
			new->sec_number = sec_number;
			if (!*sections)
				*sections = new;
			else
			{
				new->next = *sections;
				*sections = new;
			}
		}
		if (!(sec = (struct section_64 *)get_safe_address(nm_otool, (char *)sec + sizeof(*sec))))
			return (false);
		sec_number++;
	}	
	return (true);
}

bool				mach_o_64_obj_handler(t_nm_otool *nm_otool)
{
	uint32_t				i;
	struct mach_header_64	*header;
	t_lc					*lc;
	struct symtab_command	*symtab;
	t_section				*sections;

	i = 0;
	symtab = NULL;
	sections = NULL;
	if (!(header = (struct mach_header_64 *)get_safe_address(nm_otool, (char *)nm_otool->file.memory)))
		return (free_sections(sections));
	if (!(lc = (t_lc *)get_safe_address(nm_otool, (char *)nm_otool->file.memory + sizeof(*header))))
		return (free_sections(sections));
	if (!get_safe_address(nm_otool, (char *)header + sizeof(*header)))
		return (free_sections(sections));
	while (i++ < header->ncmds)
	{
		if (!get_safe_address(nm_otool, (char *)lc + sizeof(*lc)))
			return (free_sections(sections));
		if (!symtab && lc->cmd == LC_SYMTAB)
		{
			if (!(symtab = (struct symtab_command *)get_safe_address(nm_otool, (char *)lc))
				|| !get_safe_address(nm_otool, (char *)lc + sizeof(*symtab)))
				return (free_sections(sections));
		}
		if (lc->cmd == LC_SEGMENT_64)
			if (!get_sections_64(nm_otool, &sections, (struct segment_command_64 *)lc))
				return (free_sections(sections));
		if (lc->cmdsize <= sizeof(*lc))
			return (free_sections(sections));
		if (!(lc = (t_lc *)get_safe_address(nm_otool, (char *)lc + lc->cmdsize)))
			return (free_sections(sections));
	}
	if (symtab)
		return (get_symbols_64(nm_otool, symtab, sections));
	return (true);//Is this good or bad? TRUE/FALSE?
}
