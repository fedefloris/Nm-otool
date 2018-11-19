#include "nm_otool.h"

bool			set_unknown_info(t_nm_otool *nm_otool)
{
	(void)nm_otool;
	ft_printf("%s OS not supported\n", ERROR_HEADER);
	return (false);
}
