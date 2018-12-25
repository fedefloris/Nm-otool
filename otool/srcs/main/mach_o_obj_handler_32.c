#include "nm_otool.h"
#include "otool.h"

static bool			parse_text_32(t_nm_otool *nm_otool,
	struct section *section)
{
	bool			status;
	uint64_t		current_byte;
	uint64_t		position_on_row;
	unsigned char	*byte;

	if (!STRUCT_IS_SAFE(section))
		return (ERROR_LOG("section is beyond binary"));
	if (!SET(byte, nm_otool->file.memory + SWAP_ENDIAN(section->offset)))
		return (ERROR_LOG("offset beyond binary"));
	current_byte = 0;
	status = true;
	while (current_byte < SWAP_ENDIAN(section->size))
	{
		ft_printf("%08lx\t", SWAP_ENDIAN(section->addr) + current_byte);
		position_on_row = 0;
		while (position_on_row < BYTES_PER_ROW && current_byte < SWAP_ENDIAN(section->size))
		{
			if (current_byte + position_on_row + BYTES_PER_ROW < SWAP_ENDIAN(section->size))
				status = display_row(nm_otool, &byte, &current_byte, &position_on_row);
			else
				status = display_byte(nm_otool, &byte, &current_byte, &position_on_row);
			if (!status)
				return (false);
		}
		ft_printf("\n");
	}
	return (true);
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
			ft_printf("Contents of (__TEXT,__text) section\n");
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
		ft_printf("%s:\n", nm_otool->file.name);
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
	return (true);
}
