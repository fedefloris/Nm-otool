#include "nm_otool.h"
#include "nm.h"

bool				free_symbols(t_symbol *symbols)
{
	t_symbol		*tmp;

	while (symbols)
	{
		tmp = symbols;
		symbols = symbols->next;
		free(tmp);
	}
	return (false);
}
