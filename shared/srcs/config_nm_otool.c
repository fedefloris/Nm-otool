#include "nm_otool.h"

bool				config_nm_otool(t_nm_otool *nm_otool, char **argv, char **env)
{
	unsigned long	options_data;

	ft_bzero(nm_otool, sizeof(*nm_otool));
	if (!options(&argv, "abc", &options_data))
		return (false);
	nm_otool->argv = argv;
	nm_otool->env = env;
	return (true);
}
