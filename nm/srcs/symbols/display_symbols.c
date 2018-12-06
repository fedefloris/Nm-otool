#include "nm_otool.h"
#include "nm.h"

void				display_symbols(t_nm_otool *nm_otool, t_symbol **symbols)
{
	t_symbol		*sym;

	if (nm_otool->print_file_name)
		ft_printf("\n%s:\n", nm_otool->file.name);
	sort_symbols(nm_otool, symbols);
	sym = *symbols;
	while (sym)
	{
		if (nm_otool->file.format == MACH_O_32
				|| nm_otool->file.format == ELF_32)
		{
			(sym->value || (sym->type != 'U' && sym->type != 'u'))
				? ft_printf("%-9.8jx", sym->value)
				: ft_printf("%9s", "");
		}
		else
		{
			(sym->value || (sym->type != 'U' && sym->type != 'u'))
				? ft_printf("%-17.16jx", sym->value)
				: ft_printf("%17s", "");
		}
		ft_printf("%c %s\n", sym->type, sym->name);
		sym = sym->next;
	}
}
