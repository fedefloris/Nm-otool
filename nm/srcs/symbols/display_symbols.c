#include "nm_otool.h"
#include "nm.h"

void			display_symbols(t_nm_otool *nm_otool, t_symbol *symbols)
{
	if (nm_otool->print_file_name)
		ft_printf("\n%s:\n", nm_otool->file.name);
	while (symbols)
	{
		display_symbol(nm_otool, symbols);
		symbols = symbols->next;
	}
}
