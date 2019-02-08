/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_o_obj_handler_64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:31:01 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:31:02 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

static bool			parse_text_64(t_nm_otool *nm_otool,
	struct section_64 *section)
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
	while (index < SWAP_ENDIAN(section->size) && status)
	{
		SEND_TO_BUFFER(get_value_64(SWAP_ENDIAN(section->addr)
			+ index), "\t");
		position = 0;
		while (position < BYTES_PER_ROW && index < SWAP_ENDIAN(section->size))
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

static bool			text_segment_64(t_nm_otool *nm_otool,
	struct segment_command_64 *segment)
{
	struct section_64	*section;
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
			return (parse_text_64(nm_otool, section));
		}
		if (!SET(section, section + sizeof(*section)))
			return (ERROR_LOG("next section is beyond binary"));
	}
	return (true);
}

bool				mach_o_obj_handler_64(t_nm_otool *nm_otool)
{
	struct mach_header_64	*header;
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
		if (SWAP_ENDIAN(lcmd->cmd) == LC_SEGMENT_64)
			if (!text_segment_64(nm_otool, (struct segment_command_64 *)lcmd))
				return (false);
		if (!ADVANCE(lcmd, lcmd + lcmd->cmdsize))
			return (ERROR_LOG("next load command is beyond binary"));
	}
	empty_the_buffer(&nm_otool->buff);
	return (true);
}
