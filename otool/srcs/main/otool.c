#include <sys/stat.h>
#include <sys/mman.h>
#include "otool.h"

int					main(int argc, char **argv)
{
    int     i;
    int     ret;
    t_file  file;

    i = 0;
    while (++i < argc)
    {
        ft_bzero(&file, sizeof(t_file));
        if ((ret = load_file(argv[i], &file) == SUCCESS))
        {
        }
    }
    return (SUCCESS);
}
