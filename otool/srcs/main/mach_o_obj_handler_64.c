#include "nm_otool.h"
#include "otool.h"

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////START//////////////////////////////////////////
static char	ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

static int	ft_get_len(uintmax_t num, uintmax_t base)
{
	int		len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

static char	*ft_generate_string(uintmax_t num, uintmax_t base, char c)
{
	uintmax_t	sum;
	int			mod;
	int			len;
	int			i;
	char		*str;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	sum = num;
	i = 0;
	len = ft_get_len(num, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (sum)
	{
		mod = sum % base;
		sum /= base;
		str[(len--) - 1] = ft_calculate_char(mod, c);
	}
	return (str);
}

char		*ft_itoa_base_tmp(uintmax_t num, uintmax_t base, char c)
{
	char	*str;

	str = ft_generate_string(num, base, c);
	return (str);
}
//////////////////////////////////////////END////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

void		print_row(unsigned char *word)
{
	unsigned char	row[WORD_NUM * 3];
	char			*number;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (j < WORD_NUM)
	{
		number = ft_itoa_base_tmp(*word, 16, 'a');//protect malloc
		if (ft_strlen(number) == 1)
			row[i++] = '0';
		//ft_printf("%s|", number);
		ft_strcpy((char *)(row + i), number);//number);
		i += ft_strlen(number);
		row[i++] = ' ';
		j++;
		word++;
		//word = (unsigned char *)word + 1;
		////word++;
	}
	row[i - 1] = '\0';
	ft_printf("%s", row);
}

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
