/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_o_obj_handler_32.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:59 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:31:00 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

static bool			parse_text_32(t_nm_otool *nm_otool,
	struct section *section)
{
	bool			status;
	uint64_t		index;
	uint64_t		position;
	unsigned char	*byte;

	if ((index = 0) || !STRUCT_IS_SAFE(section))
		return (ERROR_LOG("section is beyond binary"));
	if (!SET(byte, nm_otool->file.memory + SWAP_ENDIAN(section->offset)))
		return (ERROR_LOG("offset beyond binary"));
	status = true;
	while (status && index < SWAP_ENDIAN(section->size))
	{
		SEND_TO_BUFFER(get_value_32(SWAP_ENDIAN(section->addr) + index), "\t");
		position = 0;
		while (status && position < BYTES_PER_ROW
			&& index < SWAP_ENDIAN(section->size))
		{
			if (index + position + BYTES_PER_ROW < SWAP_ENDIAN(section->size))
				status = display_row(nm_otool, &byte, &index, &position);
			else
				status = display_byte(nm_otool, &byte, &index, &position);
		}
		SEND_TO_BUFFER("\n");
	}
	return (status);
}

static bool			text_segment_32(t_nm_otool *nm_otool,
	struct segment_command *segment)
{
	struct section		*section;
	uint32_t			nsects;

	if (!SET(section, segment + sizeof(*segment)))
		return (ERROR_LOG("first section beyond binary"));
	if (!STRUCT_IS_SAFE(segment))
		return (ERROR_LOG("segment struct is beyond binary"));
	nsects = SWAP_ENDIAN(segment->nsects);
	while (nsects--)
	{
		if (!STRUCT_IS_SAFE(section) || !STRING_IS_SAFE(section->sectname))
			return (ERROR_LOG("section or secname is beyond binary"));
		if (!ft_strcmp(section->sectname, SECT_TEXT))
		{
			SEND_TO_BUFFER("Contents of (__TEXT,__text) section\n");
			return (parse_text_32(nm_otool, section));
		}
		if (!SET(section, section + sizeof(*section)))
			return (ERROR_LOG("next section is beyond binary"));
	}
	return (true);
}

bool				mach_o_obj_handler_32(t_nm_otool *nm_otool)
{
	struct mach_header		*header;
	struct load_command		*lcmd;
	uint32_t				ncmds;

	if (nm_otool->print_file_name)
		SEND_TO_BUFFER(nm_otool->file.name, ":\n");
	if (!SET(header, nm_otool->file.memory))
		return (ERROR_LOG("file->memory beyond binary"));
	if (!SET(lcmd, nm_otool->file.memory + sizeof(*header)))
		return (ERROR_LOG("first load command beyond binary"));
	if (!STRUCT_IS_SAFE(header))
		return (ERROR_LOG("header is beyond binary"));
	ncmds = SWAP_ENDIAN(header->ncmds);
	while (ncmds--)
	{
		if (!STRUCT_IS_SAFE(lcmd))
			return (ERROR_LOG("current load command is beyond binary"));
		if (SWAP_ENDIAN(lcmd->cmd) == LC_SEGMENT)
			if (!text_segment_32(nm_otool, (struct segment_command *)lcmd))
				return (false);
		if (!ADVANCE(lcmd, lcmd + lcmd->cmdsize))
			return (ERROR_LOG("next load command is beyond binary"));
	}
	empty_the_buffer(&nm_otool->buff);
	return (true);
}
