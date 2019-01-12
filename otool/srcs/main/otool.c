#include "nm_otool.h"
#include "otool.h"

int			main(int argc, char **argv, char **env)
{
	t_nm_otool	nm_otool;

	(void)argc;
	if (!config_nm_otool(&nm_otool, argv, env, FT_OTOOL))
		return (EXIT_FAILURE);
	if (op(&nm_otool, 'h'))
		return (display_usage());
	nm_otool.print_file_name = true;
	return (list_objs_symbols(&nm_otool, &obj_handler));
}
