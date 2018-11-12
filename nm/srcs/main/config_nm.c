#include "nm.h"

void	config_nm(t_nm *nm, int argc, char **argv)
{
	ft_bzero(nm, sizeof(*nm));
	nm->argc = argc;
	nm->argv = argv;
}
