#include "nm_otool.h"

void				*get_safe_address(t_nm_otool *nm_otool, void *address)
{
	if (address < nm_otool->file.memory
		|| address > nm_otool->file.end_of_file)
		return (NULL);
	else
		return (address);
}