#include "nm.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

static void			do_nm(t_nm *nm)
{
	ft_printf("[%d] %s\n",
			(nm->file.format == BITS_32) ? 32 : 64,
			(nm->argc == 1) ? DEFAULT : *nm->argv);
}

static t_bool		read_magic_number(t_nm *nm)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm->file.memory;
	if (magic_number == MH_MAGIC)
		nm->file.format = BITS_32;
	else if (magic_number == MH_MAGIC_64)
		nm->file.format = BITS_64;
	else
		return (FALSE);
	return (TRUE);
}

static t_bool		get_memory(t_nm *nm)
{
	t_bool			status;

	status = TRUE;
	if (status && fstat(nm->file.fd, &nm->file.stat) < 0)
		status = FALSE;
	if (status)
		nm->file.memory = mmap(0, nm->file.stat.st_size,
				PROT_READ, MAP_PRIVATE, nm->file.fd, 0);
	if (status && nm->file.memory == MAP_FAILED)
		status = FALSE;
	if (close(nm->file.fd) == -1)
		status = FALSE;
	return (TRUE);
}

int					list_object_file_symbols(t_nm *nm, char *file_name)
{
	if ((nm->file.fd = open(file_name, O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (!get_memory(nm))
		return (EXIT_FAILURE);
	if (!read_magic_number(nm))
		return (EXIT_FAILURE);
	do_nm(nm);
	if (munmap(nm->file.memory, nm->file.stat.st_size) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
