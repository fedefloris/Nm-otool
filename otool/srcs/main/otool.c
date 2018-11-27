#include <sys/stat.h>
#include <sys/mman.h>
#include <ar.h>
#include <mach-o/fat.h>
#include "otool.h"
#include "nm_otool.h"
#include "ft_printf.h"

int					otool(t_file *file)
{
    uint32_t    magic;

    magic = *(uint32_t *)file->map;
    if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
        macho_64(file);
    else if (magic == MH_MAGIC || magic == MH_CIGAM)
        macho_32(file);
    else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
        fat(file);
    else if (ft_strncmp((char *)file->map, ARMAG, SARMAG) == 0)
    {
        archive(file);
    }
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
