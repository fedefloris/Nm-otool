#include "nm_otool.h"

bool				is_safe_address(t_nm_otool *nm_otool, void *address)
{
	ft_printf("SIZ: %x\nEND: %p\nADD: %p\n",
		nm_otool->file.size, nm_otool->file.end_of_file, address);
	if (address > nm_otool->file.end_of_file)
		return (false);
	return (true);
}