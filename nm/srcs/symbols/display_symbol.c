#include "nm_otool.h"
#include "nm.h"

static void			display_64_symbol_value(t_nm_otool *nm_otool,
	t_symbol *sym, bool print_value)
{
	if (print_value)
		ft_printf("%-17.16jx", sym->value);
	else
		send_to_buffer(&nm_otool->buffer, "                 ", NULL);
}

static void			display_32_symbol_value(t_nm_otool *nm_otool,
	t_symbol *sym, bool print_value)
{
	if (print_value)
		ft_printf("%-9.8jx", sym->value);
	else
		send_to_buffer(&nm_otool->buffer, "         ", NULL);
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
	char			type[3];

	if (!sym->name || !*sym->name)
		return ;
	if (op(nm_otool, 'j'))
	{
		send_to_buffer(&nm_otool->buffer, sym->name, "\n", NULL);
		return ;
	}
	type[0] = sym->type;
	type[1] = ' ';
	type[2] = '\0';
	print_value = should_the_value_be_printed(sym);
	if (IS_MACH_O_32(nm_otool->file.format)
			|| IS_ELF_32(nm_otool->file.format))
		display_32_symbol_value(nm_otool, sym, print_value);
	else
		display_64_symbol_value(nm_otool, sym, print_value);
	send_to_buffer(&nm_otool->buffer, type, sym->name, "\n", NULL);
}
