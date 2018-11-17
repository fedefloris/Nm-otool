#include "ft_printf.h"
#include "nm_otool.h"
#include "nm.h"

int					main(int argc, char **argv, char **env)
{
	t_nm_otool	nm_otool;

	config_nm_otool(&nm_otool, argv, env);
	if (argc == 1)
		return (list_obj_symbols(&nm_otool, DEFAULT_ARGUMENT, &obj_handler));
	return (list_objs_symbols(&nm_otool, &obj_handler));
}
