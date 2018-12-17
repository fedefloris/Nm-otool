#include "nm_otool.h"

bool			set_archive_format(t_nm_otool *nm_otool)
{
	if (!ft_strncmp(nm_otool->file.memory, ARMAG, SARMAG))
		nm_otool->file.format = ARCHIVE;
	else
		return (false);
	return (true);
}
