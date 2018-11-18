#include "nm_otool.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

static bool	is_a_regular_file(t_nm_otool *nm_otool, int fd)
{
	if (!S_ISREG(nm_otool->file.mode))
	{
		close(fd);
		return (false);
	}
	return (true);
}

static bool	map_file_to_memory(t_nm_otool *nm_otool, int fd)
{
	nm_otool->file.memory = mmap(0, nm_otool->file.size,
		PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	if (nm_otool->file.memory == MAP_FAILED)
		return (false);
	return (true);
}

static bool	set_file_data(t_nm_otool *nm_otool, int fd)
{
	struct stat	stat;

	if (fstat(fd, &stat) < 0)
	{
		close(fd);
		return (false);
	}
	nm_otool->file.size = stat.st_size;
	nm_otool->file.mode = stat.st_mode;
	return (true);
}

static int	open_file(t_nm_otool *nm_otool)
{
	char			*binary_path;
	int				fd;

	if ((fd = open(nm_otool->file.name, O_RDONLY)) > 0)
		return (fd);
	if (!(binary_path = find_binary(nm_otool)))
		return (-1);
	fd = open(binary_path, O_RDONLY);
	free(binary_path);
	return (fd);
}

bool				set_file(t_nm_otool *nm_otool)
{
	int		fd;

	if ((fd = open_file(nm_otool)) < 0)
		ft_printf("%s file not found\n", ERROR_HEADER);
	else if (!set_file_data(nm_otool, fd))
		ft_printf("%s fstat call failed\n", ERROR_HEADER);
	else if (!is_a_regular_file(nm_otool, fd))
		ft_printf("%s not a regular file\n", ERROR_HEADER);
	else if (!map_file_to_memory(nm_otool, fd))
		ft_printf("%s mmap call failed\n", ERROR_HEADER);
	else if (!set_file_info(nm_otool))
		;
	else
		return (true);
	return (false);
}
