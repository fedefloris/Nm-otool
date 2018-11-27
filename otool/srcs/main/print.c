#include "ft_printf.h"
#include "otool.h"

void    print_filename(t_file *file, char *current_file)
{
    if (file->filetype == ARCHIVE)
    {
        if (!current_file)
            return ;
        ft_printf("%s(%s):\n", file->filename, current_file);
    }
    else
        ft_printf("%s:\n", file->filename);
}
