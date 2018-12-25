#include "nm_otool.h"
#include "otool.h"

bool		mach_o_obj_handler(t_nm_otool *nm_otool)
{
	if (IS_MACH_O_64(nm_otool->file.format))
		mach_o_obj_handler_64(nm_otool);
	else if (IS_MACH_O_32(nm_otool->file.format))
		mach_o_obj_handler_32(nm_otool);
	else if (IS_MACH_O_FAT(nm_otool->file.format))
		mach_o_fat_32(nm_otool);
	else if (IS_ARCHIVE(nm_otool->file.format))
	{
		nm_otool->file.format = ARCHIVE; // Useless?
		archive_handler(nm_otool);
	}
	return (true);
}
