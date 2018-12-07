#include "nm_otool.h"
#include "nm.h"

static void		display_64_symbol(t_symbol *sym)
{
	if (sym->value || (sym->type != 'U' && sym->type != 'u'))
		ft_printf("%-17.16jx", sym->value);
	else
		ft_printf("%17s", "");
	ft_printf("%c %s\n", sym->type, sym->name);
}

static void		display_32_symbol(t_symbol *sym)
{
	if (sym->value || (sym->type != 'U' && sym->type != 'u'))
		ft_printf("%-9.8jx", sym->value);
	else
		ft_printf("%9s", "");
	ft_printf("%c %s\n", sym->type, sym->name);
}

static void		display_symbol(t_nm_otool *nm_otool, t_symbol *sym)
{
	if (!sym->name || !*sym->name)
		return ;
	if (nm_otool->file.format == MACH_O_32
			|| nm_otool->file.format == ELF_32)
		display_32_symbol(sym);
	else
		display_64_symbol(sym);
}

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
