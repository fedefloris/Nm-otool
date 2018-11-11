#include "nm.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdbool.h>

static bool			get_memory(t_nm *nm, int fd)
{
	if (fstat(fd, &nm->stat) < 0)
		return (false);
	nm->memory = mmap(0, nm->stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (nm->memory == MAP_FAILED)
		return (false);
	return (true);
}

int					list_object_file_symbols(t_nm *nm, char *file_name)
{
	int				fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (!get_memory(nm, fd))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	if (close(fd) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
