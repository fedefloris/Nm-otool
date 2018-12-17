#include "nm_otool.h"

bool		set_file_info(t_nm_otool *nm_otool)
{
	if (set_archive_format(nm_otool))
		return (true);
	return (SET_FILE_INFO(nm_otool));
}
