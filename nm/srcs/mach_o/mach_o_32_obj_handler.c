#include "nm_otool.h"
#include "nm.h"

bool		mach_o_32_obj_handler(t_nm_otool *nm_otool)
{
	ft_printf("Mach-o-32, File_name: %s\n", nm_otool->file.name);
	return (true);
}
