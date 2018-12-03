#include "nm_otool.h"
#include "nm.h"

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

int					get_ar_name_length(char  *ar_name)
{
	char    *ar_name_len;

	ar_name_len = ft_strstr(ar_name, "/");
	if (ar_name_len)
		return (ft_atoi(ar_name_len + 1));
	return (-1);
}

bool				handle_archive_objects(t_nm_otool *nm_otool, struct ar_hdr *ar_ptr)
{
	int             ar_size;
	int             ar_name_len;
	char            *filename;
	t_file          ar;

	while (ar_ptr)
	{
		ar_size = ft_atoi(ar_ptr->ar_size);
		filename = (char *)ar_ptr + sizeof(struct ar_hdr);
		print_filename(file, filename);
		ar_name_len = get_ar_name_length(ar_ptr->ar_name);
		ft_bzero(&ar, sizeof(t_file));
		ar.memory = (void *)ar_ptr + sizeof(struct ar_hdr)\
				 + ar_name_len;
		ar.format = ARCHIVE;
		otool(&ar);
		if ((void *)(ar_ptr = (void *)ar_ptr + ar_size + sizeof(struct ar_hdr)) >= (void *)nm_otool->file.memory + file->file_size)
			ar_ptr = NULL;
	}
	return (true);
}

bool				mach_o_archive(t_nm_otool *nm_otool)
{
	struct ar_hdr   *header;
	struct ar_hdr   *ar_ptr;
	int             ar_size;

	header = (struct ar_hdr *)((void *)nm_otool->file.memory + SARMAG);
	ar_size = ft_atoi(header->ar_size);
	ar_ptr = (struct ar_hdr *)((void *)nm_otool->file.memory + SARMAG\
			+ ar_size + sizeof(struct ar_hdr));
	return (handle_archive_objects(nm_otool, ar_ptr));
}
