#include "nm_otool.h"
#include "nm.h"

static bool			mach_o_32_read_symbols(t_nm_otool *nm_otool,
		struct nlist *array, t_section *sections,
		t_symbol **symbols, t_sym *symtab)
{
	uint32_t		i;
	char			*str;
	char			*stringtable;

	i = 0;
	if (!(stringtable = (char *)get_safe_address(nm_otool,
			(char *)nm_otool->file.memory + symtab->stroff)))
		return (false);
	while (i < symtab->nsyms)
	{
		if (!get_safe_address(nm_otool, (char *)&array[i] + sizeof(array[i])))
			return (false);
		if (!(str = (char *)get_safe_address(nm_otool,
				(char *)stringtable + array[i].n_un.n_strx)))
			return (false);
		if (!string_is_safe(nm_otool, (char *)str))
			return (false);
		if ((array[i].n_type & N_STAB) == 0)
			if (!(add_symbol(symbols, array[i].n_value,
					get_type(array[i].n_type, (uint64_t)array[i].n_value,
					array[i].n_sect, sections), str)))
				return (false);
		i++;
	}
	return (true);
}

static bool			mach_o_32_get_symbols(t_nm_otool *nm_otool,
		t_sym *symtab, t_section *sections)
{
	struct nlist	*array;
	t_symbol		*symbols;

	symbols = NULL;
	if (!(array = (struct nlist *)get_safe_address(nm_otool,
			(char *)nm_otool->file.memory + symtab->symoff)))
		return (free_symbols(symbols));
	if (!(mach_o_32_read_symbols(nm_otool, array,
			sections, &symbols, symtab)))
		return (free_symbols(symbols));
	display_symbols(nm_otool, symbols);
	free_sections(sections);
	free_symbols(symbols);
	return (true);
}

static int			mach_o_32_get_first_load_command(t_nm_otool *nm_otool,
		t_lc **lc)
{
	struct mach_header		*header;

	if (!(header = (struct mach_header *)get_safe_address(
			nm_otool, (char *)nm_otool->file.memory)))
		return (-1);
	if (!(*lc = (t_lc *)get_safe_address(
			nm_otool, (char *)nm_otool->file.memory + sizeof(*header))))
		return (-1);
	if (!get_safe_address(nm_otool, (char *)header + sizeof(*header)))
		return (-1);
	return ((int)header->ncmds);
}

bool				mach_o_32_obj_handler(t_nm_otool *nm_otool)
{
	int						number_of_commands;
	t_lc					*lc;
	t_sym					*symtab;
	t_section				*sections;

	sections = NULL;
	if ((number_of_commands =
			mach_o_32_get_first_load_command(nm_otool, &lc)) < 0)
		return (free_sections(sections));
	if ((symtab = mach_o_read_load_commands(nm_otool, lc,
			&sections, number_of_commands)))
		return (mach_o_32_get_symbols(nm_otool, symtab, sections));
	return (true);//Is this good or bad? TRUE/FALSE?
}

