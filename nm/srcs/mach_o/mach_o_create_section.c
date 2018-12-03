#include "nm_otool.h"
#include "nm.h"

bool    			mach_o_create_section(t_section **sections,
		char *sectname, unsigned char sec_number)
{
	t_section				*new;

	if (!(new = (t_section *)ft_memalloc(sizeof(t_section))))
		return (false);
	new->name = sectname;
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
