#include "nm_otool.h"
#include "nm.h"

bool				free_sections(t_section *sections)
{
	t_section		*tmp;

	while (sections)
	{
		tmp = sections;
		sections = sections->next;
		free(tmp);
	}
	return (false);
}