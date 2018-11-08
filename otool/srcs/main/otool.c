#include <sys/stat.h>
#include <sys/mman.h>
#include "otool.h"
#include "nm_otool.h"
#include "ft_printf.h"

int					otool(t_file *file)
{
    uint32_t    magic_num;

    magic_num = *(uint32_t *)file->map;
    if (magic_num == MH_MAGIC_64)
        ft_printf("64 bit obj\n");
    else if (magic_num == MH_MAGIC)
        ft_printf("32 bit obj\n");
    return (SUCCESS);
}

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
            ft_printf("return status of otool: %d\n", otool(&file));
            munmap(file.map, file.file_size);
        }
    }
    return (SUCCESS);
}
