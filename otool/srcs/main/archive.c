#include <ar.h>
#include "otool.h"
#include "ft_printf.h"

int     archive(t_file *file)
{
    struct ar_hdr   *header;
    struct ar_hdr   *ar_ptr;
    int             ar_size;
    char            *filename;
    t_file          ar;

    header = (struct ar_hdr *)((void *)file->map + SARMAG);
    ar_size = ft_atoi(header->ar_size);
    ar_ptr = (struct ar_hdr *)((void *)file->map + SARMAG\
            + ar_size + sizeof(struct ar_hdr));
    while (ar_ptr)
    {
        ar_size = ft_atoi(ar_ptr->ar_size);
        filename = (char *)ar_ptr + sizeof(struct ar_hdr);
        ft_printf("%s\n", filename);
        ft_bzero(&ar, sizeof(t_file));
        ar.map = (void *)ar_ptr + sizeof(struct ar_hdr)\
                 + ft_strlen(filename) + 1 + (sizeof(int) * 2);
        otool(&ar);
        if ((void *)(ar_ptr = (void *)ar_ptr + ar_size + sizeof(struct ar_hdr)) >= (void *)file->map + file->file_size)
            ar_ptr = NULL;
    }
    return (SUCCESS);
}
