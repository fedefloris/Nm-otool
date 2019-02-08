/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:05 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:06 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static int		safe_atoi(t_nm_otool *nm_otool, char *str)
{
	int		result;

	result = 0;
	while (ADDRESS_IS_SAFE(str))
	{
		if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*(str++) - '0');
		else
			return (result);
	}
	return (-1);
}

static int		get_ar_name_length(t_nm_otool *nm_otool,
	char *ar_name)
{
	char	*ptr;

	ptr = ar_name;
	while (ADDRESS_IS_SAFE(ptr))
	{
		if (*ptr && *ptr == '/')
			return (safe_atoi(nm_otool, ptr + 1));
		ptr++;
	}
	return (-1);
}

static bool		handle_archive_object(t_nm_otool *nm_otool,
	struct ar_hdr *ar_ptr, t_file *file_data, int *ar_size)
{
	int		ar_name_len;
	char	*filename;

	if (!SET(filename, (char*)(ar_ptr + 1))
		|| !STRING_IS_SAFE(filename))
		return (ERROR_LOG("archive: filename beyond binary"));
	if ((*ar_size = safe_atoi(nm_otool, ar_ptr->ar_size)) < 0)
		return (ERROR_LOG("archive: ar_size bad format"));
	if ((ar_name_len = get_ar_name_length(nm_otool, ar_ptr->ar_name)) < 0)
		return (ERROR_LOG("archive: ar_name_len bad format"));
	SEND_TO_BUFFER((nm_otool->routine == FT_NM) ? "\n" : "",
		nm_otool->file.name, "(", filename, "):\n");
	ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
	nm_otool->file.name = file_data->name;
	nm_otool->file.size = (off_t)(*ar_size);
	nm_otool->file.memory = (char *)(ar_ptr + 1) + ar_name_len;
	if ((nm_otool->file.end_of_file = file_data->memory
		+ file_data->size - 1) > file_data->end_of_file)
		return (ERROR_LOG("archive: ar_size bad size."));
	nm_otool->file.reversed_endian = file_data->reversed_endian;
	return (true);
}

static bool		handle_archive_objects(t_nm_otool *nm_otool,
	struct ar_hdr *ar_ptr, bool print_file_name)
{
	t_file	file_data;
	int		ar_size;
	bool	status;

	status = true;
	file_data = nm_otool->file;
	nm_otool->print_file_name = false;
	while (true)
	{
		if (!handle_archive_object(nm_otool,
			ar_ptr, &file_data, &ar_size))
			return (false);
		if (!SET_FILE_INFO(nm_otool) || !obj_handler(nm_otool))
			status = false;
		nm_otool->file = file_data;
		if (!ADVANCE(ar_ptr, (char*)ar_ptr
			+ sizeof(struct ar_hdr) + ar_size))
			break ;
	}
	nm_otool->print_file_name = print_file_name;
	empty_the_buffer(&nm_otool->buff);
	return (status);
}

bool			archive_handler(t_nm_otool *nm_otool)
{
	struct ar_hdr	*ar_ptr;
	int				ar_size;

	if (nm_otool->routine == FT_OTOOL)
		SEND_TO_BUFFER("Archive : ", nm_otool->file.name, "\n");
	if (!SET(ar_ptr, nm_otool->file.memory + SARMAG)
		|| !STRUCT_IS_SAFE(ar_ptr))
		return (ERROR_LOG("archive: not enough space for ar_hdr"));
	if ((ar_size = safe_atoi(nm_otool, ar_ptr->ar_size)) < 0)
		return (ERROR_LOG("archive: ar_size bad format"));
	if (!SET(ar_ptr, (char*)(ar_ptr + 1) + ar_size)
		|| !STRUCT_IS_SAFE(ar_ptr))
		return (ERROR_LOG("archive: not enough space for ar_hdr"));
	return (handle_archive_objects(nm_otool, ar_ptr,
		nm_otool->print_file_name));
}
