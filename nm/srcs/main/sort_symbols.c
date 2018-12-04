#include "nm_otool.h"
#include "nm.h"

void			sort_symbols(t_nm_otool *nm_otool, t_symbol **symbols)
{
	if (!*symbols || !(*symbols)->next || op(nm_otool, 'p'))
		return ;
	*symbols = merge_sort_symbols(*symbols, &ft_strcmp);
}
