#include "nm_otool.h"
#include "nm.h"

void			display_symbols(t_nm_otool *nm_otool, t_symbol *symbols)
{
	if (nm_otool->print_file_name)
		SEND_TO_BUFFER("\n", nm_otool->file.name, ":\n");
	while (symbols)
	{
		display_symbol(nm_otool, symbols);
		symbols = symbols->next;
	}
	empty_the_buffer(&nm_otool->buffer);
}
