#include "nm_otool.h"
#include "nm.h"

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
	int				ar_size;
	int				ar_name_len;
	char			*filename;
	t_file			file_data;

	file_data = nm_otool->file;
	while (ar_ptr)
	{
		filename = (char *)ar_ptr + sizeof(struct ar_hdr);
        ft_printf("%s(%s):\n", nm_otool->file.name, filename);
		ar_size = ft_atoi(ar_ptr->ar_size);
		ar_name_len = get_ar_name_length(ar_ptr->ar_name);

		ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
		nm_otool->file.name = file_data.name;
		nm_otool->file.size = (off_t)ar_size;//Check is safe.
		nm_otool->file.memory = (void *)ar_ptr + sizeof(struct ar_hdr) + ar_name_len;
		nm_otool->file.end_of_file = file_data.memory + file_data.size - 1;
		nm_otool->file.endianness = file_data.endianness;
		set_mach_o_info(nm_otool);//Maybe fails
		set_mach_o_info(nm_otool);//Maybe fails

		if ((void *)(ar_ptr = (void *)ar_ptr + ar_size + sizeof(struct ar_hdr)) >= (void *)file_data.memory + file_data.size)
			ar_ptr = NULL;
	}
	nm_otool->file = file_data;
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
