#include "nm_otool.h"
#include "nm.h"

static void		send_file_name(t_buffer *buffer, char *file_name)
{
	send_to_buffer(&buffer, "\n");
	send_to_buffer(&buffer, nm_otool->file.name);
	send_to_buffer(&buffer, ":\n");
}

void			display_symbols(t_nm_otool *nm_otool, t_symbol *symbols)
{
	t_buffer buffer;

	config_buffer(&buffer);
	if (nm_otool->print_file_name)
		send_file_name(&buffer, nm_otool->file.name);
	while (symbols)
	{
		display_symbol(nm_otool, symbols);
		symbols = symbols->next;
	}
	empty_the_buffer(&buffer);
}
