#include "nm.h"
#include <fcntl.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/mman.h>
#include <sys/stat.h>

int					main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_putendl("nm: nothing here");
	return (0);
}
