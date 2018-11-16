#include "nm_otool.h"
#include "ft_printf.h"
#include <stdlib.h>

int 		list_object_files_symbols(int argc, char **argv, char **env)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (argc == 1)
		return (list_object_file_symbols(DEFAULT_ARGUMENT, NULL));
	while (*(++argv))
	{
		if (list_object_file_symbols(*argv, env) == EXIT_FAILURE)
		{
			ft_printf("ft_nm: %s: File format not recognized\n", *argv);
			exit_status = EXIT_FAILURE;
		}
	}
	return (exit_status);
}
