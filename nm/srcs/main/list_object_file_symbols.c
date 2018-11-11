#include "nm.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

static t_bool		read_magic_number(t_nm *nm)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm->memory;
	if (magic_number == MH_MAGIC)
		nm->file_format = BITS_32;
	else if (magic_number == MH_MAGIC_64)
		nm->file_format = BITS_64;
	else
		return (FALSE);
	return (TRUE);
}

static t_bool		get_memory(t_nm *nm)
{
	if (fstat(nm->fd, &nm->stat) < 0)
		return (FALSE);
	nm->memory = mmap(0, nm->stat.st_size, PROT_READ, MAP_PRIVATE, nm->fd, 0);
	if (nm->memory == MAP_FAILED)
		return (FALSE);
	return (TRUE);
}

int					list_object_file_symbols(t_nm *nm, char *file_name)
{
	if ((nm->fd = open(file_name, O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (!get_memory(nm))
	{
		close(nm->fd);
		return (EXIT_FAILURE);
	}
	if (close(nm->fd) == -1)
		return (EXIT_FAILURE);
	if (!read_magic_number(nm))
		return (EXIT_FAILURE);
	if (munmap(nm->memory, nm->stat.st_size) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
