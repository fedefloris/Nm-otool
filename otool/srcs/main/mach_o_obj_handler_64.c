#include "nm_otool.h"
#include "otool.h"

bool		parse_text_64(struct section_64 *section, t_nm_otool *nm_otool)
{
	struct section_64	*sect_ptr;
	struct section_64	*sect_addr;
	uint32_t			i;
	uint32_t			j;
	unsigned char		word;

	sect_ptr = (void *)nm_otool->file.memory + section->offset;
	sect_addr = section;
	i = 0;
	while (i < section->size)
	{
		ft_printf("%016lx\t", (void *)(sect_addr->addr + i));
		j = 0;
		while (j < WORD_NUM && (i + j) < section->size)
		{
			word = *(unsigned char *)sect_ptr;
			if (i + j + WORD_NUM < section->size)
			{
				print_row((unsigned char *)sect_ptr);
				sect_ptr = (void *)sect_ptr + WORD_NUM;
				j += WORD_NUM;
			}
			else
			{
				ft_printf("%02x ", word);
				sect_ptr = (void *)sect_ptr + sizeof(char);
				j++;
			}
		}
		ft_printf("\n");
		i += WORD_NUM;
	}
	return (true);
}

bool		text_segment_64(struct segment_command_64 *segment, t_nm_otool *nm_otool)
{
	struct section_64			*section;
	uint32_t                    nsects;

	if (!SET(section, segment + sizeof(*segment)))
		return (ERROR_LOG("first section beyond binary"));
	if (!STRUCT_IS_SAFE(segment))
		return (ERROR_LOG("segment struct is beyond binary"));
	nsects = segment->nsects;
	while (nsects--)
	{
		if (!STRUCT_IS_SAFE(section) || !STRING_IS_SAFE(section->sectname))
			return (ERROR_LOG("section or secname is beyond binary"));
		if (ft_strcmp(section->sectname, SECT_TEXT) == 0)//refactor
		{
			ft_printf("Contents of (__TEXT,__text) section\n");
			parse_text_64(section, nm_otool);//return good value
		}
		if (!SET(section, section + sizeof(*section)))
			return (ERROR_LOG("next section is beyond binary"));
	}
	return (true);
}

bool		mach_o_obj_handler_64(t_nm_otool *nm_otool)
{
	struct mach_header_64       *header;
	struct load_command         *lcmd;
	uint32_t					ncmds;

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
			if (!text_segment_64((struct segment_command_64 *)lcmd, nm_otool))
				return (false);
		if (!SET(lcmd, lcmd + lcmd->cmdsize))
			return (ERROR_LOG("next load command is beyond binary"));
	}
	return (true);
}