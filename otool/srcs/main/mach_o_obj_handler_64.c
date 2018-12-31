#include "nm_otool.h"
#include "otool.h"

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

//Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
static char	*ft_itoa_base_tmp(uintmax_t num, uintmax_t base, char c)
{
	uintmax_t	sum;
	int			mod;
	int			len;
	char		*str;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	sum = num;
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

static char			*get_formatted_byte(uint64_t byte)
{
	static char		formatted[17];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 16);
	if (!(number = ft_itoa_base_tmp(byte, 16, 'a'))) // Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
		return ("");
	formatted_index = 15;
	if ((number_index = ft_strlen(number) - 1) > formatted_index)
		number_index = formatted_index;
	while (number_index >= 0)
		formatted[formatted_index--] = number[number_index--];
	ft_strdel(&number);
	return (formatted);
}

static bool			parse_text_64(t_nm_otool *nm_otool,
	struct section_64 *section)
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
		// ft_printf("%016lx\t", SWAP_ENDIAN(section->addr) + current_byte);
		SEND_TO_BUFFER(get_formatted_byte(SWAP_ENDIAN(section->addr)
			+ current_byte), "\t");
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
		SEND_TO_BUFFER("\n");
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
	empty_the_buffer(&nm_otool->buffer);
	return (true);
}
