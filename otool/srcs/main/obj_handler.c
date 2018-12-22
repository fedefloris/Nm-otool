#include "nm_otool.h"
#include "otool.h"

bool            obj_handler(t_nm_otool *nm_otool)
{
    uint32_t    magic;

    magic = *(uint32_t *)nm_otool->file.memory;
    if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
        mach_o_obj_handler_64(nm_otool);
    else if (magic == MH_MAGIC || magic == MH_CIGAM)
        mach_o_obj_handler_32(nm_otool);
    else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
        mach_o_fat_32(nm_otool);
    else if (ft_strncmp((char *)nm_otool->file.memory, ARMAG, SARMAG) == 0)
    {
        ft_printf("Archive : %s\n", nm_otool->file.name);
        nm_otool->file.format = ARCHIVE;
        archive_handler(nm_otool);
        
    }
    return (true);
}
