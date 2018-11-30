#include "nm_otool.h"
#include "nm.h"

t_sym				*mach_o_read_load_commands(t_nm_otool *nm_otool,
		t_lc *lc, t_section **sections, int number_of_commands)
{
	t_sym			*symtab;

	symtab = NULL;
	while (number_of_commands--)
	{
		if (!get_safe_address(nm_otool, (char *)lc + sizeof(*lc)))
			return (NULL);
		if (!symtab && lc->cmd == LC_SYMTAB)
		{
			if (!(symtab = (t_sym *)get_safe_address(nm_otool, (char *)lc))
				|| !get_safe_address(nm_otool, (char *)lc + sizeof(*symtab)))
				return (NULL);
		}
		if (lc->cmd == LC_SEGMENT_64)
			if (!mach_o_64_get_sections(nm_otool, sections,
					(struct segment_command_64 *)lc))
				return (NULL);
		if (lc->cmdsize <= sizeof(*lc))
			return (NULL);
		if (!(lc = (t_lc *)get_safe_address(nm_otool,
				(char *)lc + lc->cmdsize)))
			return (NULL);
	}
	return (symtab);
}
