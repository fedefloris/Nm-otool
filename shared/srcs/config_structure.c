#include "nm_otool.h"

void				config_structure(t_nm_otool *nm_otool, char **env)
{
	ft_bzero(nm_otool, sizeof(*nm_otool));
	nm_otool->env = env;
}
