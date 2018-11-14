#include <ar.h>
#include "otool.h"
#include "ft_printf.h"

int     archive(t_file *file)
{
    struct ar_hdr   *header;
    struct ar_hdr   *ar_ptr;

    header = (struct ar_hdr *)file->map;
    ar_ptr = (void *)file->map + SARMAG;
    ft_printf("%s\n", ar_ptr->ar_name);
    return (SUCCESS);
}
