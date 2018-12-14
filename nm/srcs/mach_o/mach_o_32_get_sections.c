#include "nm_otool.h"
#include "nm.h"

bool		mach_o_32_get_sections(t_nm_otool *nm_otool,
	t_section **sections, struct segment_command *segment, bool reset)
{
	static unsigned char	sec_number = 1;
	struct section			*sec;
	uint32_t				i;

	if (reset)
	{
		sec_number = 1;
		return (true);
	}
	i = 0;
	if(!SET(sec, segment + sizeof(*segment)))
		return (ERROR_LOG("section beyond binary"));
	while (i++ < segment->nsects)
	{
		if (!STRUCT_IS_SAFE(sec))
			return (ERROR_LOG("section beyond binary"));
		if (!string_is_safe(nm_otool, (char *)sec->sectname))
			return (ERROR_LOG("sec->sect_name is beyond binary"));
		if (!ft_strcmp(sec->sectname, SECT_DATA)
				|| !ft_strcmp(sec->sectname, SECT_BSS)
				|| !ft_strcmp(sec->sectname, SECT_TEXT))
			if (!(mach_o_create_section(sections, sec->sectname, sec_number)))
				return (ERROR_LOG("malloc failed: create section"));
		if (!(NEXT_STRUCT(sec)))
			return (ERROR_LOG("section beyond binary"));
		sec_number++;
	}
	return (true);
}
