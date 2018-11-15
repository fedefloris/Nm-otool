#include "nm.h"
#include "ft_printf.h"

int					list_object_file_symbols(char *file_name)
{
	t_file		file;

	if (!set_mapped_file(&file, file_name))
		return (EXIT_FAILURE);
	if (!unset_mapped_file(&file))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
