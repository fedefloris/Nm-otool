#include "nm_otool.h"
#include <sys/mman.h>

bool		unset_file(t_nm_otool *nm_otool)
{
	if (munmap(nm_otool->file.memory, nm_otool->file.size) < 0)
	{
		WARNING_LOG("munmap call failed");
		return (false);
	}
	return (true);
}
