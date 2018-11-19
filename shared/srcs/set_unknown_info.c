#include "nm_otool.h"

bool			set_unknown_info(t_nm_otool *nm_otool)
{
	(void)nm_otool;
	ERROR_LOG("OS not supported");
	return (false);
}
