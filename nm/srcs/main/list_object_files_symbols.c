#include "nm.h"

int 		list_object_files_symbols(int argc, char **argv)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (argc == 1)
		return (list_object_file_symbols(DEFAULT_ARGUMENT));
	while (argv[++argc])
	{
		if (list_object_file_symbols(argv[argc]) == false)
			exit_status = EXIT_FAILURE;
	}
	return (exit_status);
}
