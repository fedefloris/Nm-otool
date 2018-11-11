#include "nm.h"

int					main(int argc, char **argv)
{
	t_nm			nm;

	nm.argv = argv;
	nm.argc = argc;
	return (list_object_files_symbols(&nm));
}
