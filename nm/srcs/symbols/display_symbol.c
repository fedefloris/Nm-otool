#include "nm_otool.h"
#include "nm.h"

static void	  display_64_symbol_value(t_symbol *sym)
{
	if (sym->value || (sym->type != 'U' && sym->type != 'u'))
		ft_printf("%-17.16jx", sym->value);
	else
		ft_printf("%17s", "");
}

static void	  display_32_symbol_value(t_symbol *sym)
{
	if (sym->value || (sym->type != 'U' && sym->type != 'u'))
		ft_printf("%-9.8jx", sym->value);
	else
		ft_printf("%9s", "");
}

void		      display_symbol(t_nm_otool *nm_otool, t_symbol *sym)
{
	if (!sym->name || !*sym->name)
		return ;
	if (nm_otool->file.format == MACH_O_32
			|| nm_otool->file.format == ELF_32)
		display_32_symbol_value(sym);
	else
		display_64_symbol_value(sym);
	ft_printf("%c %s\n", sym->type, sym->name);
}
