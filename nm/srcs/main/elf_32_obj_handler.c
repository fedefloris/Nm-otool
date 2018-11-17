#include "ft_printf.h"
#include "nm_otool.h"
#include "nm.h"

bool		elf_32_obj_handler(t_nm_otool *nm_otool)
{
	ft_printf("Elf32, File_name: %s\n", nm_otool->file.name);
	return (true);
}
