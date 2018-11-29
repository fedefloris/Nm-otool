#include "nm_otool.h"
#include "nm.h"

static bool			mach_o_64_create_section(t_section **sections,
		struct section_64 *sec, unsigned char sec_number)
{
	t_section				*new;

	if (!(new = (t_section *)ft_memalloc(sizeof(t_section))))
		return (false);
	new->name = sec->sectname;
	new->sec_number = sec_number;
	if (!*sections)
		*sections = new;
	else
	{
		new->next = *sections;
		*sections = new;
	}
	return (true);
}

bool				mach_o_64_get_sections(t_nm_otool *nm_otool,
		t_section **sections, struct segment_command_64 *segment)
{
	uint32_t				i;
	static unsigned char	sec_number = 1;
	struct section_64		*sec;

	i = 0;
	if (!(sec = (struct section_64 *)get_safe_address(
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
			if (!(mach_o_64_create_section(sections, sec, sec_number)))
				return (false);
		if (!(sec = (struct section_64 *)get_safe_address(
				nm_otool, (char *)sec + sizeof(*sec))))
			return (false);
		sec_number++;
	}
	return (true);
}