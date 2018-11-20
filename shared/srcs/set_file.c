#include "nm_otool.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

static bool	is_a_regular_file(t_nm_otool *nm_otool, int fd)
{
	if (!S_ISREG(nm_otool->file.mode))
	{
		if (close(fd) == -1)
			WARNING_LOG("close call failed");
		return (false);
	}
	return (true);
}

static bool	map_file_to_memory(t_nm_otool *nm_otool, int fd)
{
	nm_otool->file.memory = mmap(0, nm_otool->file.size,
		PROT_READ, MAP_PRIVATE, fd, 0);
	if (close(fd) == -1)
		WARNING_LOG("close call failed");
	if (nm_otool->file.memory == MAP_FAILED)
		return (false);
	nm_otool->file.end_of_file = nm_otool->file.memory + nm_otool->file.size - 1;
	return (true);
}

static bool	set_file_data(t_nm_otool *nm_otool, int fd)
{
	struct stat	stat;

	if (fstat(fd, &stat) < 0)
	{
		if (close(fd) == -1)
			WARNING_LOG("close call failed");
		return (false);
	}
	nm_otool->file.size = stat.st_size;
	nm_otool->file.mode = stat.st_mode;
	return (true);
}

static int	open_file(t_nm_otool *nm_otool)
{
	char	*binary_path;
	int		fd;

	if ((fd = open(nm_otool->file.name, O_RDONLY)) > 0)
		return (fd);
	if (!(binary_path = find_binary(nm_otool)))
		return (-1);
	fd = open(binary_path, O_RDONLY);
	free(binary_path);
	return (fd);
}

bool		set_file(t_nm_otool *nm_otool)
{
	int		fd;

	if ((fd = open_file(nm_otool)) < 0)
		ERROR_LOG("file not found");
	else if (!set_file_data(nm_otool, fd))
		ERROR_LOG("fstat call failed");
	else if (nm_otool->file.size == 0)
		ERROR_LOG("Bad size");
	else if (!is_a_regular_file(nm_otool, fd))
		ERROR_LOG("not a regular file");
	else if (!map_file_to_memory(nm_otool, fd))
		ERROR_LOG("mmap call failed");
	else if (!set_file_info(nm_otool))
		;
	else
		return (true);
	return (false);
}
