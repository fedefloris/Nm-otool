#include "nm_otool.h"

int			main(int argc, char **argv, char **env)
{
	return (list_object_files_symbols(argc, argv, env));
}
