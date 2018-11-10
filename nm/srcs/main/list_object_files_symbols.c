#include "nm.h"

int 		list_object_files_symbols(int argc, char **argv)
{
	int	exit_status;
	int i;

	exit_status = EXIT_SUCCESS;
	if (argc == 1)
		return (list_object_file_symbols("a.out"));
	i = 1;
	while (i < argc)
	{
		if (list_object_file_symbols(argv[i]) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
		i++;
	}
	return (exit_status);
}
