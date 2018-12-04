#include "nm_otool.h"

char			*get_safe_address(t_nm_otool *nm_otool, char *address)
{
	if (address < nm_otool->file.memory
		|| address > nm_otool->file.end_of_file)
		return (NULL);
	return (address);
}
