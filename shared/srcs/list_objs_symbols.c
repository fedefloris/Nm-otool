#include "nm_otool.h"
#include "ft_printf.h"
#include <stdlib.h>

int				list_objs_symbols(t_nm_otool *nm_otool, t_obj_handler obj_handler)
{
	int				exit_status;
	char			**argv;

	argv = nm_otool->argv;
	exit_status = EXIT_SUCCESS;
	if (!(argv + 1))
		return (list_obj_symbols(nm_otool, DEFAULT_ARGUMENT, obj_handler));
	while (*(++argv))
	{
		if (list_obj_symbols(nm_otool, *argv, obj_handler) == EXIT_FAILURE)
		{
			ft_printf("ft_nm: %s: File format not recognized\n", *argv);
			exit_status = EXIT_FAILURE;
		}
	}
	return (exit_status);
}
