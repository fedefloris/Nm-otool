#include "nm_otool.h"
#include "otool.h"

void    print_filename(t_file *file, char *current_file)
{
    if (file->format == MACH_O_ARCHIVE)
    {
        if (!current_file)
            return ;
        ft_printf("%s(%s):\n", file->name, current_file);
    }
    else
        ft_printf("%s:\n", file->name);
}
