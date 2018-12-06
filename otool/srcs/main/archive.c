#include "nm_otool.h"
#include "otool.h"

int     get_ar_name_length(char  *ar_name)
{
    char    *ar_name_len;

    ar_name_len = ft_strstr(ar_name, "/");
    if (ar_name_len)
        return (ft_atoi(ar_name_len + 1));
    return (-1);
}

bool     handle_archive_objects(t_file *file, struct ar_hdr *ar_ptr)
{
    int             ar_size;
    int             ar_name_len;
    char            *filename;
    t_nm_otool      nm_otool;

    while (ar_ptr)
    {
        ar_size = ft_atoi(ar_ptr->ar_size);
        filename = (char *)ar_ptr + sizeof(struct ar_hdr);
        print_filename(file, filename);
        ar_name_len = get_ar_name_length(ar_ptr->ar_name);
        ft_bzero(&nm_otool.file, sizeof(t_file));
        nm_otool.file.memory = (void *)ar_ptr + sizeof(struct ar_hdr)\
                 + ar_name_len;
        nm_otool.file.format = MACH_O_ARCHIVE;
        otool_obj_handler(&nm_otool);
        if ((void *)(ar_ptr = (void *)ar_ptr + ar_size + sizeof(struct ar_hdr)) >= (void *)file->memory + file->size)
            ar_ptr = NULL;
    }
    return (true);
}

bool      archive(t_file *file)
{
    struct ar_hdr   *header;
    struct ar_hdr   *ar_ptr;
    int             ar_size;

    header = (struct ar_hdr *)((void *)file->memory + SARMAG);
    ar_size = ft_atoi(header->ar_size);
    ar_ptr = (struct ar_hdr *)((void *)file->memory + SARMAG\
            + ar_size + sizeof(struct ar_hdr));
    return (handle_archive_objects(file, ar_ptr));
}
