#include "nm_otool.h"

bool				config_nm_otool(t_nm_otool *nm_otool, char **argv,
	char **env, unsigned char routine)
{
	ft_bzero(nm_otool, sizeof(*nm_otool));
	if (!options(&argv, (routine == FT_NM)? NM_OPTIONS : OTOOL_OPTIONS, &nm_otool->options))
		return (false);
	nm_otool->argv = argv;
	nm_otool->env = env;
	nm_otool->print_file_name = (*argv && *(argv + 1)) ? true : false;
	nm_otool->routine = FT_OTOOL;
	nm_otool->mach_o_32 = &mach_o_obj_handler_32;
	nm_otool->mach_o_64 = &mach_o_obj_handler_64;
	return (true);
}
