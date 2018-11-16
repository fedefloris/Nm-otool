#include "nm_otool.h"
#include <stdlib.h>

int					list_object_file_symbols(t_nm_otool *nm_otool, char *file_name)
{
	ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
	nm_otool->file.name = file_name;
	if (!set_mapped_file(nm_otool))
		return (EXIT_FAILURE);
	if (!unset_mapped_file(nm_otool))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
