#include "nm_otool.h"
#include "nm.h"

static void			display_64_symbol_value(t_symbol *sym, bool print_value)
{
	if (print_value)
		ft_printf("%-17.16jx", sym->value);
	else
		ft_printf("%17s", "");
}

static void			display_32_symbol_value(t_symbol *sym, bool print_value)
{
	if (print_value)
		ft_printf("%-9.8jx", sym->value);
	else
		ft_printf("%9s", "");
}

static bool			should_the_value_be_printed(t_symbol *sym)
{
	if ((sym->type == 'u' || ft_tolower(sym->type) == 'i')
		&& sym->value)
		return (true);
	return (sym->type != 'w'
		&& ft_tolower(sym->type) != 'u'
		&& ft_tolower(sym->type) != 'i');
}

void				display_symbol(t_nm_otool *nm_otool, t_symbol *sym)
{
	bool			print_value;

	print_value = should_the_value_be_printed(sym);
	if (!sym->name || !*sym->name)
		return ;
	if (op(nm_otool, 'j'))
	{
		ft_printf("%s\n", sym->name);
		return ;
	}
	if (nm_otool->file.format == MACH_O_32
			|| nm_otool->file.format == ELF_32)
		display_32_symbol_value(sym, print_value);
	else
		display_64_symbol_value(sym, print_value);
	ft_printf("%c %s\n", sym->type, sym->name);
}
