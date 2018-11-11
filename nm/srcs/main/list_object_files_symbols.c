#include "nm.h"

int 		list_object_files_symbols(t_nm *nm)
{
	int	exit_status;
	int i;

	exit_status = EXIT_SUCCESS;
	if (nm->argc == 1)
		return (list_object_file_symbols(nm, "a.out"));
	i = 1;
	while (i < nm->argc)
	{
		if (list_object_file_symbols(nm, nm->argv[i]) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
		i++;
	}
	return (exit_status);
}
