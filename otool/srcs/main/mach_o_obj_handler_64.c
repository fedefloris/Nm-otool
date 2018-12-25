#include "nm_otool.h"
#include "otool.h"

static bool			parse_text_64(t_nm_otool *nm_otool,
	struct section_64 *section)
{
	uint64_t		current_byte;
	uint64_t		position_on_row;
	unsigned char	*byte;

	if (!STRUCT_IS_SAFE(section))
		return (ERROR_LOG("section is beyond binary"));
	if (!SET(byte, nm_otool->file.memory + section->offset))
		return (ERROR_LOG("offset beyond binary"));
	current_byte = 0;
	while (current_byte < section->size)
	{
		ft_printf("%016lx\t", section->addr + current_byte);
		position_on_row = 0;
		while (position_on_row < BYTES_PER_ROW && current_byte < section->size)
		{
			if (current_byte + position_on_row + BYTES_PER_ROW < section->size)
			{
				if (!get_safe_address(nm_otool, (char *)byte + (BYTES_PER_ROW - 1)))
					return (ERROR_LOG("current row is beyond binary"));
				print_row(byte);
				if (!SET(byte, byte + BYTES_PER_ROW))
					return (ERROR_LOG("next row is beyond binary"));
				position_on_row += BYTES_PER_ROW;
				current_byte += BYTES_PER_ROW;
			}
			else
			{
				if (!get_safe_address(nm_otool, (char *)byte))
					return (ERROR_LOG("current row is beyond binary"));
				ft_printf("%02x ", *byte);
				if (!SET(byte, byte + sizeof(*byte)))
					return (ERROR_LOG("next byte is beyond binary"));
				position_on_row++;
				current_byte++;
			}
		}
		ft_printf("\n");
	}
	return (true);
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
	nsects = segment->nsects;
	while (nsects--)
	{
		if (!STRUCT_IS_SAFE(section) || !STRING_IS_SAFE(section->sectname))
			return (ERROR_LOG("section or secname is beyond binary"));
		if (!ft_strcmp(section->sectname, SECT_TEXT))
		{
			ft_printf("Contents of (__TEXT,__text) section\n");
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
		ft_printf("%s:\n", nm_otool->file.name);
	if (!SET(header, nm_otool->file.memory))
		return (ERROR_LOG("file->memory beyond binary"));
	if (!SET(lcmd, nm_otool->file.memory + sizeof(*header)))
		return (ERROR_LOG("first load command beyond binary"));
	if (!STRUCT_IS_SAFE(header))
		return (ERROR_LOG("header is beyond binary"));
	ncmds = header->ncmds;
	while (ncmds--)
	{
		if (!STRUCT_IS_SAFE(lcmd))
			return (ERROR_LOG("current load command is beyond binary"));
		if (lcmd->cmd == LC_SEGMENT_64)
			if (!text_segment_64(nm_otool, (struct segment_command_64 *)lcmd))
				return (false);
		if (!SET(lcmd, lcmd + lcmd->cmdsize))
			return (ERROR_LOG("next load command is beyond binary"));
	}
	return (true);
}
