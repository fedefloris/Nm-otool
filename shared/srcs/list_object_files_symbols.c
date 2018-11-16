#include "nm_otool.h"
#include <stdlib.h>

int					list_object_files_symbols(int argc, char **argv, char **env)
{
	int				exit_status;
	t_nm_otool		nm_otool;

	exit_status = EXIT_SUCCESS;
	config_structure(&nm_otool, env);
	if (argc == 1)
		return (list_object_file_symbols(&nm_otool, DEFAULT_ARGUMENT));
	while (*(++argv))
	{
		if (list_object_file_symbols(&nm_otool, *argv) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
	}
	return (exit_status);
}
