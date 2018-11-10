#include "nm_otool.h"
#include "otool.h"
#include "ft_printf.h"

int     text_segment(struct load_command *lcmd)
{
    struct segment_command_64   *segment;
    uint32_t                    i;

    segment = (struct segment_command_64 *)lcmd;
    i = 0;
    while (i < segment->nsects)
    {
        ft_printf("%s\n", segment->segname);
        segment = (void *)segment + segment->cmdsize;
        i++;
    }
    return (SUCCESS);
}

int     macho_64(t_file *file)
{
    struct mach_header_64       *header;
    struct load_command         *lcmd;
    uint32_t                    i;

    header = (struct mach_header_64 *)file->map;
    lcmd = (void *)file->map + sizeof(*header);
    i = 0;
    while (i < header->ncmds)
    {
        if (lcmd->cmd == LC_SEGMENT_64)
        {
            text_segment(lcmd);
        }
        lcmd = (void *)lcmd + lcmd->cmdsize;
        i++;
    }
    return (SUCCESS);
}
