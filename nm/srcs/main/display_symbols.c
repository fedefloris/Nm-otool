#include "nm_otool.h"
#include "nm.h"

void				display_symbols(t_nm_otool *nm_otool, t_symbol *symbols)
{
	if (nm_otool->print_file_name)
		ft_printf("\n%s:\n", nm_otool->file.name);
	sort_symbols(nm_otool, &symbols);
	while (symbols)
	{
		if (nm_otool->file.format == MACH_O_32_FORMAT)
		{
			(symbols->value)
				? ft_printf("%-9.8jx", symbols->value)
				: ft_printf("%9s", "");
		}
		else
		{
			(symbols->value)
				? ft_printf("%-17.16jx", symbols->value)
				: ft_printf("%17s", "");
		}
		ft_printf("%c %s\n", symbols->type, symbols->name);
		symbols = symbols->next;
	}
}
