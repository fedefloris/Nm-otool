#include <ar.h>
#include "otool.h"
#include "ft_printf.h"

int     get_ar_name_length(char  *ar_name)
{
    char    *ar_name_len;

    ar_name_len = ft_strstr(ar_name, "/");
    if (ar_name_len)
        return (ft_atoi(ar_name_len + 1));
    return (-1);
}

int     archive(t_file *file)
{
    struct ar_hdr   *header;
    struct ar_hdr   *ar_ptr;
    int             ar_size;
    int             ar_name_len;
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
        ar_name_len = get_ar_name_length(ar_ptr->ar_name);
        ft_bzero(&ar, sizeof(t_file));
        ar.map = (void *)ar_ptr + sizeof(struct ar_hdr)\
                 + ar_name_len;
        otool(&ar);
        if ((void *)(ar_ptr = (void *)ar_ptr + ar_size + sizeof(struct ar_hdr)) >= (void *)file->map + file->file_size)
            ar_ptr = NULL;
    }
    return (SUCCESS);
}