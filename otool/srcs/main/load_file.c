#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include "ft_printf.h"
#include "otool.h"

int	check_file_stat(char *filename, struct stat *buf)
{
	if (buf->st_mode & S_IFREG)
		ft_printf("regular file\n");
	else if (buf->st_mode & S_IFDIR)
		ft_printf("'%s': Is a directory\n", filename);
	return (SUCCESS);
}

int load_file(char *filename, t_file *file)
{
    int			fd;
    struct stat	buf;

    if (!filename)
        return (FAILURE);
    if ((fd = open(filename, O_RDONLY)) < 0)
        return (FAILURE);
    if (fstat(fd, &buf) < 0)
    {
        close(fd);
        return (FAILURE);
    }
	check_file_stat(filename, &buf);
    if ((file->map = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
        close(fd);
        return (FAILURE);
    }
    return (SUCCESS);
}
