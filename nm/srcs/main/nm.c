#include "ft_printf.h"
#include "nm_otool.h"
#include "nm.h"

static bool	obj_handler(t_nm_otool *nm_otool)
{
	ft_printf("File_name: %s\n", nm_otool->file.name);
	return (true);
}

int					main(int argc, char **argv, char **env)
{
	t_nm_otool	nm_otool;

	config_nm_otool(&nm_otool, argv, env);
	if (argc == 1)
		return (list_obj_symbols(&nm_otool, DEFAULT_ARGUMENT, &obj_handler));
	return (list_objs_symbols(&nm_otool, &obj_handler));
}
