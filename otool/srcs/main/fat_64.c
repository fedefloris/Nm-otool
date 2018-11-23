#include <mach-o/fat.h>
#include "ft_printf.h"
#include "nm_otool.h"
#include "otool.h" 

int fat_64(t_file *file)
{
    t_file              fat;
    struct fat_header   *header;
    struct fat_arch     *arch;
    uint32_t            nfat_arch;
    uint32_t            i;

    header = (struct fat_header *)file->map;
    nfat_arch = swap_endian(header->nfat_arch);
    arch = (struct fat_arch *)((void *)file->map + sizeof(struct fat_header));
    i = 0;
    while (i < nfat_arch)
    {
        ft_bzero(&fat, sizeof(t_file));
        fat.map = (void *)file->map + swap_endian(arch->offset);
        macho_64(&fat);
        arch = (struct fat_arch *)((void *)arch + sizeof(struct fat_arch));
        i++;
    }
    return (SUCCESS);
}
