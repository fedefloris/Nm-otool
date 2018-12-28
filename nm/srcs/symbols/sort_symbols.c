#include "nm_otool.h"
#include "nm.h"

static int	cmp_value_ascendent(t_symbol *sym1, t_symbol *sym2)
{
	if (sym1->value > sym2->value)
		return (1);
	if (sym1->value < sym2->value)
		return (-1);
	return (0);
}

static int	cmp_name_ascendent(t_symbol *sym1, t_symbol *sym2)
{
	int		name_cmp;

	return ((sym1->name && sym2->name &&
		(name_cmp = ft_strcmp(sym1->name, sym2->name)))
			? name_cmp
			: cmp_value_ascendent(sym1, sym2));
}

static int	cmp_name_descendent(t_symbol *sym1, t_symbol *sym2)
{
	return (-cmp_name_ascendent(sym1, sym2));
}

void		sort_symbols(t_nm_otool *nm_otool, t_symbol **symbols)
{
	int (*cmp)();

	if (!*symbols || !(*symbols)->next || op(nm_otool, 'p'))
		return ;
	cmp = &cmp_name_ascendent;
	if (op(nm_otool, 'r'))
		cmp = &cmp_name_descendent;
	*symbols = merge_sort_symbols(*symbols, cmp);
}
