#include "nm_otool.h"
#include "otool.h"

bool		obj_handler(t_nm_otool *nm_otool)
{
	// if (IS_ARCHIVE(nm_otool->file.format))
	// 	return (archive_handler(nm_otool));
	// if (IS_ELF(nm_otool->file.format))
	// 	return (elf_obj_handler(nm_otool));
	return (MAC_OBJ_HANDLER(nm_otool));
}
