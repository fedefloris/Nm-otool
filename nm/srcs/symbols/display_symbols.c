#include "nm_otool.h"
#include "nm.h"

void					display_symbols(t_nm_otool *nm_otool, t_symbol **symbols)
{
	t_symbol		*sym;

	if (nm_otool->print_file_name)
		ft_printf("\n%s:\n", nm_otool->file.name);
	sort_symbols(nm_otool, symbols);
	sym = *symbols;
	while (sym)
	{
		display_symbol(nm_otool, sym);
		sym = sym->next;
	}
}
