#include "nm_otool.h"
#include "ft_printf.h"

static bool	obj_handler(t_nm_otool *nm_otool)
{
	ft_printf("File_name: %s\n", nm_otool->file.name);
	return (true);
}

int			main(int argc, char **argv, char **env)
{
	t_nm_otool		nm_otool;

	(void)argc;
	config_nm_otool(&nm_otool, argv, env);
	return (list_objs_symbols(&nm_otool, &obj_handler));
}
