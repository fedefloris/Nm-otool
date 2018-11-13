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

static bool			read_magic_number(t_nm *nm)
{
	uint32_t		magic_number;

	magic_number = *(uint32_t *)nm->file.memory;
	if (magic_number == MH_MAGIC)
		nm->file.format = BITS_32;
	else if (magic_number == MH_MAGIC_64)
		nm->file.format = BITS_64;
	else
		return (false);
	return (true);
}

static bool			get_memory(t_nm *nm)
{
	bool				status;

	status = true;
	if (status && fstat(nm->file.fd, &nm->file.stat) < 0)
		status = false;
	if (status)
		nm->file.memory = mmap(0, nm->file.stat.st_size,
				PROT_READ, MAP_PRIVATE, nm->file.fd, 0);
	if (status && nm->file.memory == MAP_FAILED)
		status = false;
	if (status && !S_ISREG(nm->file.stat.st_mode))
		status = false;
	return (status);
}

int					list_object_file_symbols(t_nm *nm, char *file_name)
{
	if ((nm->file.fd = open(file_name, O_RDONLY)) < 0 ||
			!get_memory(nm) ||
			!read_magic_number(nm))
		return (EXIT_FAILURE);
	do_nm(nm);
	close(nm->file.fd); // maybe check return status
	if (munmap(nm->file.memory, nm->file.stat.st_size) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
