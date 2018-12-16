#include "nm_otool.h"
#include "nm.h"

static int		safe_atoi(t_nm_otool *nm_otool, char *str)
{
	int				result;

	result = 0;
	while (get_safe_address(nm_otool, str))
	{
		if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*(str++) - '0');
		else
			return (result);
	}
	return (-1);
}

static int		get_ar_name_length(t_nm_otool *nm_otool,
	char *ar_name)//Super unsafe function.
{
	char			*ptr;

	ptr = ar_name;
	while (get_safe_address(nm_otool, ptr))
	{
		if (*ptr && *ptr == '/')
			return (safe_atoi(nm_otool, ptr + 1));
		ptr++;
	}
	return (-1);
}

// static bool		handle_archive_object(t_nm_otool *nm_otool,
// 	struct ar_hdr *ar_ptr)
// {
//
// }

static bool		handle_archive_objects(t_nm_otool *nm_otool,
	struct ar_hdr *ar_ptr)
{
	int				ar_size;
	int				ar_name_len;
	char			*file_name;
	bool			status;
	t_file			file_data;

	status = true;
	file_data = nm_otool->file;
	while (true)
	{
		if (!SET(file_name, ar_ptr + sizeof(*ar_ptr))
			|| !string_is_safe(nm_otool, file_name))
			return (ERROR_LOG("archive: file_name beyond binary"));
        ft_printf("\n%s(%s):\n", nm_otool->file.name, file_name);
		if ((ar_size = safe_atoi(nm_otool, ar_ptr->ar_size)) < 0)
			return (ERROR_LOG("archive: ar_size bad format"));
		if ((ar_name_len = get_ar_name_length(nm_otool, ar_ptr->ar_name)) < 0)
			return (ERROR_LOG("archive: ar_name_len bad format"));
		ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
		nm_otool->file.name = file_data.name;
		nm_otool->file.size = (off_t)ar_size;//Check is safe.
		nm_otool->file.memory = (char *)ar_ptr + sizeof(struct ar_hdr) + ar_name_len;
		if ((nm_otool->file.end_of_file = file_data.memory + file_data.size - 1) > file_data.end_of_file)//Inspect for godd logic.
			return (ERROR_LOG("archive: ar_size bad size."));
		nm_otool->file.endian_is_reversed = file_data.endian_is_reversed;
		if (!SET_FILE_INFO(nm_otool) || !obj_handler(nm_otool))
			status = false;
		nm_otool->file = file_data;
		if (!SET(ar_ptr, ar_ptr + ar_size + sizeof(struct ar_hdr)))
			break ;
	}
	return (status);
}

bool			archive_handler(t_nm_otool *nm_otool)
{
	struct ar_hdr   *ar_ptr;
	int             ar_size;

	if(!SET(ar_ptr, nm_otool->file.memory + SARMAG)
		|| !STRUCT_IS_SAFE(ar_ptr))
		return (ERROR_LOG(""));
	if ((ar_size = safe_atoi(nm_otool, ar_ptr->ar_size)) < 0)
		return (ERROR_LOG(""));
	if (!SET(ar_ptr, (char*)ar_ptr + ar_size + sizeof(*ar_ptr))
		|| !STRUCT_IS_SAFE(ar_ptr))
		return (ERROR_LOG(""));
	return (handle_archive_objects(nm_otool, ar_ptr));
}
