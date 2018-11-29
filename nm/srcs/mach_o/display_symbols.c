#include "nm_otool.h"
#include "nm.h"

void				display_symbols(t_nm_otool *nm_otool, t_symbol *symbols)
{
	while (symbols)
	{
		symbols = sort_symbols(nm_otool, symbols);
		(symbols->value) ? ft_printf("%-17.16jx", symbols->value) : ft_printf("%17s", "");
		ft_printf("%c %s\n", symbols->type, symbols->name);
		symbols = symbols->next;
	}
}