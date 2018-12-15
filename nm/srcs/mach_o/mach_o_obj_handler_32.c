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
	if (!SET(stringtable, nm_otool->file.memory + SWAP_ENDIAN(symtab->stroff)))
		return (ERROR_LOG("no stringtable found"));
	while (i < SWAP_ENDIAN(symtab->nsyms))
	{
		if (!STRUCT_IS_SAFE(&array[i]))
			return (ERROR_LOG("struct nlist is not a good size"));
		if (!SET(str, stringtable + SWAP_ENDIAN(array[i].n_un.n_strx)))
			return (ERROR_LOG("symbol name goes beyond the binary limit"));
		if (!string_is_safe(nm_otool, str))
			return (ERROR_LOG("symbol name goes beyond the binary limit"));
		if ((SWAP_ENDIAN(array[i].n_type) & N_STAB) == 0)
			if (!(add_symbol(symbols, SWAP_ENDIAN(array[i].n_value),
					mach_o_get_type(SWAP_ENDIAN(array[i].n_type),
					(uint64_t)SWAP_ENDIAN(array[i].n_value),
					SWAP_ENDIAN(array[i].n_sect), sections), str)))
				return (ERROR_LOG("malloc failed: t_symbol symbol"));
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
	if (!SET(array, nm_otool->file.memory + SWAP_ENDIAN(symtab->symoff)))
		return (free_symbols(symbols));
	if (!(mach_o_32_read_symbols(nm_otool, array,
			sections, &symbols, symtab)))
		return (free_symbols(symbols));
	sort_symbols(nm_otool, &symbols);
	display_symbols(nm_otool, symbols);
	mach_o_free_sections(sections);
	free_symbols(symbols);
	return (true);
}

static int			mach_o_32_get_first_load_command(t_nm_otool *nm_otool,
		t_lc **lc)
{
	struct mach_header		*header;

	if (!SET(header, nm_otool->file.memory))
		return (-1);
	if (!SET(*lc, header + sizeof(*header)))
		return (-1);
	return ((STRUCT_IS_SAFE(header)) ? (int)SWAP_ENDIAN(header->ncmds) : -1);
}

bool				mach_o_obj_handler_32(t_nm_otool *nm_otool)
{
	int						number_of_commands;
	t_lc					*lc;
	t_sym					*symtab;
	t_section				*sections;

	sections = NULL;
	if ((number_of_commands =
			mach_o_32_get_first_load_command(nm_otool, &lc)) < 0)
		return (mach_o_free_sections(sections));
	if ((symtab = mach_o_read_load_commands(nm_otool, lc,
			&sections, number_of_commands)))
		return (mach_o_32_get_symbols(nm_otool, symtab, sections));
	return (true);//Is this good or bad? TRUE/FALSE?
}
