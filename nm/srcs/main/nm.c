#include "nm.h"

int					main(int argc, char **argv)
{
	t_nm			nm;

	config_nm(&nm, argc, argv);
	return (list_object_files_symbols(&nm));
}
