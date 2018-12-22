#include "nm_otool.h"
#include "otool.h"

bool		parse_text_64(struct section_64 *section, t_file *file)
{
	struct section_64	*sect_ptr;
	struct section_64	*sect_addr;
	uint32_t			i;
	uint32_t			j;
	unsigned char		word;

	sect_ptr = (void *)file->memory + section->offset;
	sect_addr = section;
	i = 0;
	while (i < section->size)
	{
		ft_printf("%016lx\t", (void *)(sect_addr->addr + i));
		j = 0;
		while (j < WORD_NUM && (i + j) < section->size)
		{
			word = *(unsigned char *)sect_ptr;
			ft_printf("%02x ", word);
			//swap_64(word);
			sect_ptr = (void *)sect_ptr + sizeof(char);
			j++;
		}
		ft_printf("\n");
		i += WORD_NUM;
	}
	return (true);
}

bool		text_segment_64(struct load_command *lcmd, t_file *file)
{
	struct segment_command_64   *segment;
	struct section_64			*section;
	void						*sect_ptr;
	uint32_t                    i;

	segment = (struct segment_command_64 *)lcmd;
	sect_ptr = (void *)(segment + 1);
	i = 0;
	while (i < segment->nsects)
	{
		section = (struct section_64 *)sect_ptr;
		if (ft_strcmp(section->sectname, SECT_TEXT) == 0)
		{
			ft_printf("Contents of (__TEXT,__text) section\n");
			parse_text_64(section, file);
		}
		sect_ptr += sizeof(struct section_64);
		i++;
	}
	return (true);
}

bool		filetype_64(struct mach_header_64 *header)
{
	if (header->filetype == MH_OBJECT)
		ft_printf("filetype: object\n");
	else if (header->filetype == MH_EXECUTE)
		ft_printf("filetype: executable\n");
	return (true);
}

bool		mach_o_obj_handler_64(t_nm_otool *nm_otool)
{
	struct mach_header_64       *header;
	struct load_command         *lcmd;
	t_file						*file;
	uint32_t                    i;

	file = &nm_otool->file;
	if (nm_otool->print_file_name)
		ft_printf("%s:\n", file->name);
	header = (struct mach_header_64 *)file->memory;
	lcmd = (void *)file->memory + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lcmd->cmd == LC_SEGMENT_64)
			text_segment_64(lcmd, file);
		lcmd = (void *)lcmd + lcmd->cmdsize;
		i++;
	}
	return (true);
}
