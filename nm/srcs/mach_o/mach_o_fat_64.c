#include "nm_otool.h"
#include "nm.h"

bool		mach_o_fat_64(t_nm_otool *nm_otool)
{
	ft_printf("Mach-fat-64, File_name: %s\n", nm_otool->file.name);
	return (true);
	//MAKE THIS FUNCTION
}
