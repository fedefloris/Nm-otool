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
	bool			status;
	t_file			file_data;

	status = true;
	file_data = nm_otool->file;
	while (true)
	{
		if (!(SET(filename, ar_ptr + sizeof(*ar_ptr))))
			return (false);
		if (!string_is_safe(nm_otool, filename))
			return (false);
        ft_printf("\n%s(%s):\n", nm_otool->file.name, filename);

		ar_size = ft_atoi(ar_ptr->ar_size);//Protect this (maybe is is not '\0' Terminated??)
		if ((ar_name_len = get_ar_name_length(ar_ptr->ar_name)) < 0)
			return (false);

		ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
		nm_otool->file.name = file_data.name;
		nm_otool->file.size = (off_t)ar_size;//Check is safe.
		nm_otool->file.memory = (void *)ar_ptr + sizeof(struct ar_hdr) + ar_name_len;
		nm_otool->file.end_of_file = file_data.memory + file_data.size - 1;
		nm_otool->file.endianness = file_data.endianness;

		if (!set_mach_o_info(nm_otool) || !mach_o_obj_handler(nm_otool))
			status = false;

		if (!(SET(ar_ptr, ar_ptr + ar_size + sizeof(struct ar_hdr))))
			break ;
	}
	nm_otool->file = file_data;
	return (status);
}

bool				mach_o_archive(t_nm_otool *nm_otool)
{
	struct ar_hdr   *header;
	struct ar_hdr   *ar_ptr;
	int             ar_size;

	if(!(SET(header, nm_otool->file.memory + SARMAG)))
		return (false);
	if (!STRUCT_IS_SAFE(header))
		return (false);
	ar_size = ft_atoi(header->ar_size);//Protect size of string (Ends with ' ' not '\0')
	if (!(SET(ar_ptr, nm_otool->file.memory + SARMAG + ar_size + sizeof(struct ar_hdr))))
		return (false);
	return (handle_archive_objects(nm_otool, ar_ptr));
}
