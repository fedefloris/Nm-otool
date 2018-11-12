#include "nm.h"

int 		list_object_files_symbols(t_nm *nm)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (nm->argc == 1)
		return (list_object_file_symbols(nm, DEFAULT));
	while (*(++nm->argv))
	{
		if (list_object_file_symbols(nm, *nm->argv) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
	}
	return (exit_status);
}
