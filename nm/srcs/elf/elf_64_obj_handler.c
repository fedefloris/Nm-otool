#include "ft_printf.h"
#include "nm_otool.h"
#include "nm.h"

bool		elf_64_obj_handler(t_nm_otool *nm_otool)
{
	ft_printf("Elf64, File_name: %s\n", nm_otool->file.name);
	return (true);
}
