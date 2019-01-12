#include "nm_otool.h"
#include "nm.h"

int			main(int argc, char **argv, char **env)
{
	t_nm_otool	nm_otool;

	(void)argc;
	if (!config_nm_otool(&nm_otool, argv, env, FT_NM))
		return (EXIT_FAILURE);
	if (op(&nm_otool, 'h'))
		return (display_usage());
	if (!*nm_otool.argv)
		return (list_obj_symbols(&nm_otool, DEFAULT_ARGUMENT, &obj_handler));
	return (list_objs_symbols(&nm_otool, &obj_handler));
}
