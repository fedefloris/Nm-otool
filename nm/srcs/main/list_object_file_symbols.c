#include "nm.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

static void 	*get_memory(fd)
{
	struct stat	file_stat;
	void 				*memory;

	if (fstat(fd, &file_stat) < 0)
		return (NULL);
	memory = mmap(0, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (memory == MAP_FAILED)
		return (NULL);
	return (memory);
}

int    				list_object_file_symbols(char *file_name)
{
	void 		*memory;
	int			fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (!(memory = get_memory(fd)))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	if (close(fd) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
