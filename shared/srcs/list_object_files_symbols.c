#include "nm_otool.h"
#include "ft_printf.h"
#include <stdlib.h>

int 		list_object_files_symbols(int argc, char **argv)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (argc == 1)
		return (list_object_file_symbols(DEFAULT_ARGUMENT));
	while (*(++argv))
	{
		if (list_object_file_symbols(*argv) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
	}
	return (exit_status);
}
