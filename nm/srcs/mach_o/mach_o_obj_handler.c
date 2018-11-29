#include "nm_otool.h"
#include "nm.h"

bool		mach_o_obj_handler(t_nm_otool *nm_otool)
{
	if (nm_otool->file.format == MACH_O_32_FORMAT)
		return (mach_o_32_obj_handler(nm_otool));
	if (nm_otool->file.format == MACH_O_64_FORMAT)
		return (mach_o_64_obj_handler(nm_otool));
	if (nm_otool->file.format == MACH_O_FAT_32)
		return (mach_fat_32_obj_handler(nm_otool));
	if (nm_otool->file.format == MACH_O_FAT_64)
		return (mach_fat_64_obj_handler(nm_otool));
	return (false);
}
