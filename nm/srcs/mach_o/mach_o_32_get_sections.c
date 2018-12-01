#include "nm_otool.h"
#include "nm.h"

bool				mach_o_32_get_sections(t_nm_otool *nm_otool,
		t_section **sections, struct segment_command *segment, bool reset)
{
	uint32_t				i;
	static unsigned char	sec_number = 1;
	struct section			*sec;

	if (reset)
	{
		sec_number = 1;
		return (true);
	}
	i = 0;
	if (!(sec = (struct section *)get_safe_address(
			nm_otool, (char *)segment + sizeof(*segment))))
		return (false);
	while (i++ < segment->nsects)
	{
		if (!get_safe_address(nm_otool, (char *)sec + sizeof(*sec)))
			return (false);
		if (!string_is_safe(nm_otool, (char *)sec->sectname))
			return (false);
		if (!ft_strcmp(sec->sectname, SECT_DATA)
				|| !ft_strcmp(sec->sectname, SECT_BSS)
				|| !ft_strcmp(sec->sectname, SECT_TEXT))
			if (!(mach_o_create_section(sections, sec->sectname, sec_number)))
				return (false);
		if (!(sec = (struct section *)get_safe_address(
				nm_otool, (char *)sec + sizeof(*sec))))
			return (false);
		sec_number++;
	}
	return (true);
}
