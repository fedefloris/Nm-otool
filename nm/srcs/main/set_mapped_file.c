#include "nm.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

// static bool			read_magic_number(t_file *file)
// {
// 	uint32_t		magic_number;
//
// 	magic_number = *(uint32_t *)file->memory;
// 	if (magic_number == MH_MAGIC)
// 		file->format = BITS_32;
// 	else if (magic_number == MH_MAGIC_64)
// 		file->format = BITS_64;
// 	else
// 		return (false);
// 	return (true);
// }

bool      			set_mapped_file(t_file *file, char *file_name)
{
	bool				status;
	struct stat	stat;
	int					fd;

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
	close(fd); // maybe check return status
	return (status);
}
