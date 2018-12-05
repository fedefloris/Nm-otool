#include "ft_printf.h"
#include "otool.h"

void    print_filename(t_file2 *file, char *current_file2)
{
    if (file->filetype == ARCHIVE)
    {
        if (!current_file2)
            return ;
        ft_printf("%s(%s):\n", file->filename, current_file2);
    }
    else
        ft_printf("%s:\n", file->filename);
}
