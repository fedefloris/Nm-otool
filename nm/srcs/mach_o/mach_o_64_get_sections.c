#include "nm_otool.h"
#include "nm.h"

bool				mach_o_64_get_sections(t_nm_otool *nm_otool,
		t_section **sections, struct segment_command_64 *segment, bool reset)
{
	uint32_t				i;
	static unsigned char	sec_number = 1;
	struct section_64		*sec;

	if (reset)
	{
		sec_number = 1;
		return (true);
	}
	i = 0;
	if(!SET(sec, segment + sizeof(*segment)))
		return (false);
	while (i++ < segment->nsects)
	{
		if (!STRUCT_IS_SAFE(sec))
			return (false);
		if (!string_is_safe(nm_otool, (char *)sec->sectname))
			return (false);
		if (!ft_strcmp(sec->sectname, SECT_DATA)
				|| !ft_strcmp(sec->sectname, SECT_BSS)
				|| !ft_strcmp(sec->sectname, SECT_TEXT))
			if (!(mach_o_create_section(sections, sec->sectname, sec_number)))
				return (false);
		if (!(NEXT_STRUCT(sec)))
			return (false);
		sec_number++;
	}
	return (true);
}
