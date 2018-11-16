#include "nm_otool.h"

void		config_nm_otool(t_nm_otool *nm_otool, char **argv, char **env)
{
	ft_bzero(nm_otool, sizeof(*nm_otool));
	nm_otool->argv = argv;
	nm_otool->env = env;
}
