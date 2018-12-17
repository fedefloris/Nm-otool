#include "nm_otool.h"
#include "otool.h"

bool            otool_obj_handler(t_nm_otool *nm_otool)
{
    t_file      *file;
    uint32_t    magic;

    file = &nm_otool->file;
    magic = *(uint32_t *)file->memory;
    if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
        macho_64(file);
    else if (magic == MH_MAGIC || magic == MH_CIGAM)
        macho_32(file);
    else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
        fat(file);
    else if (ft_strncmp((char *)file->memory, ARMAG, SARMAG) == 0)
    {
        ft_printf("Archive : %s\n", file->name);
        file->format = ARCHIVE;
        archive(file);
    }
    return (true);
}
