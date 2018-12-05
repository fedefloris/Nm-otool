#include <mach-o/fat.h>
#include <mach/machine.h>
#include "ft_printf.h"
#include "nm_otool.h"
#include "otool.h"

int process_fat(struct fat_arch *arch, uint32_t nfat_arch, t_file *file,\
        int (*macho)(t_file *file))
{
    struct fat_arch *fat_ptr;
    uint32_t        i;
    t_file          fat;

    fat_ptr = arch;
    i = 0;
    while (i < nfat_arch)
    {
        ft_bzero(&fat, sizeof(t_file));
        fat.map = (void *)file->memory + swap_endian(fat_ptr->offset);
        fat.filetype = FAT;
        macho(&fat);
        fat_ptr = (struct fat_arch *)((void *)fat_ptr + sizeof(struct fat_arch));
        i++;
    }
    return (SUCCESS);
}

int handle_fat(struct fat_arch *arch, uint32_t nfat_arch, t_file *file)
{
    int ret;

    ret = FAILURE;
    if (swap_endian(arch->cputype) == CPU_TYPE_X86_64)
    {
        process_fat(arch, nfat_arch, file, &macho_64);
        ret = SUCCESS;
    }
    else if (swap_endian(arch->cputype) == CPU_TYPE_I386)
    {
        process_fat(arch, nfat_arch, file, &macho_32);
        ret = SUCCESS;
    }
    return (ret);
}

int fat(t_file *file)
{
    struct fat_header   *header;
    struct fat_arch     *arch;
    uint32_t            nfat_arch;

    ft_printf("%s:\n", file->name);
    header = (struct fat_header *)file->memory;
    nfat_arch = swap_endian(header->nfat_arch);
    arch = (struct fat_arch *)((void *)file->memory + sizeof(struct fat_header));
    handle_fat(arch, nfat_arch, file);
    return (SUCCESS);
}
