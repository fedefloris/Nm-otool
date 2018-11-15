#include "nm_otool.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

bool      			set_mapped_file(t_file *file, char *file_name, char **env)
{
	bool				status;
	struct stat	stat;
	int					fd;

	(void)env;
	status = true;
	file->name = file_name;
	if ((fd = open(file->name, O_RDONLY)) < 0)
		status = false;
	if (status && fstat(fd, &stat) < 0)
		status = false;
	file->size = stat.st_size;
	if (status)
		file->memory = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (status && file->memory == MAP_FAILED)
		status = false;
	if (status && !S_ISREG(stat.st_mode))
		status = false;
	if (fd != -1)
		close(fd);
	if (status && set_file_format(file) == false)
		status = false;
	return (status);
}
