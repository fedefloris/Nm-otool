#include "nm_otool.h"
#include "otool.h"

bool		parse_text(struct section *section, t_nm_otool *nm_otool)
{
	struct section		*sect_ptr;
	struct section		*sect_addr;
	uint32_t			i;
	uint32_t			j;
	unsigned char		word;

	sect_ptr = (void *)nm_otool->file.memory + section->offset;
	sect_addr = section;
	i = 0;
	while (i < section->size)
	{
		ft_printf("%08lx\t", (void *)(size_t)(sect_addr->addr + i));
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

bool		text_segment(struct load_command *lcmd, t_nm_otool *nm_otool)
{
	struct segment_command		*segment;
	struct section  			*section;
	void						*sect_ptr;
	uint32_t					i;

	segment = (struct segment_command *)lcmd;
	sect_ptr = (void *)(segment + 1);
	i = 0;
	while (i < segment->nsects)
	{
		section = (struct section *)sect_ptr;
		if (ft_strcmp(section->sectname, SECT_TEXT) == 0)
		{
			ft_printf("Contents of (__TEXT,__text) section\n");
			parse_text(section, nm_otool);
		}
		sect_ptr += sizeof(struct section);
		i++;
	}
	return (true);
}

bool		filetype(struct mach_header *header)
{
	if (header->filetype == MH_OBJECT)
		ft_printf("filetype: object\n");
	else if (header->filetype == MH_EXECUTE)
		ft_printf("filetype: executable\n");
	return (true);
}

bool		mach_o_obj_handler_32(t_nm_otool *nm_otool)
{
	struct mach_header		*header;
	struct load_command		*lcmd;
	uint32_t				i;

	if (nm_otool->print_file_name)
		ft_printf("%s:\n", nm_otool->file.name);
	header = (struct mach_header *)nm_otool->file.memory;
	lcmd = (void *)nm_otool->file.memory + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lcmd->cmd == LC_SEGMENT)
			text_segment(lcmd, nm_otool);
		lcmd = (void *)lcmd + lcmd->cmdsize;
		i++;
	}
	return (true);
}
