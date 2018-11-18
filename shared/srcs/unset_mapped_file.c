#include "nm_otool.h"
#include "ft_printf.h"
#include <sys/mman.h>

bool		unset_mapped_file(t_nm_otool *nm_otool)
{
	if (munmap(nm_otool->file.memory, nm_otool->file.size) < 0)
	{
		ft_printf("%s munmap call failed\n", WARNING_HEADER);
		return (false);
	}
	return (true);
}
