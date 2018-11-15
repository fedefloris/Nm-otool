#include "nm_otool.h"
#include <stdlib.h>

int					list_object_file_symbols(char *file_name, char **env)
{
	t_file		file;

	if (!set_mapped_file(&file, file_name, env))
		return (EXIT_FAILURE);
	if (!unset_mapped_file(&file))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
