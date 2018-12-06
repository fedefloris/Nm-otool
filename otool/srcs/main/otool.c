#include "nm_otool.h"
#include "otool.h"

int					main(int argc, char **argv, char **env)
{
	t_nm_otool	nm_otool;

	(void)argc;
	if (!config_nm_otool(&nm_otool, argv, env, OTOOL_OPTIONS))
		return (EXIT_FAILURE);
	return (list_objs_symbols(&nm_otool, &otool_obj_handler));
}
