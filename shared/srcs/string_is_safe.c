#include "nm_otool.h"

bool				string_is_safe(t_nm_otool *nm_otool, char *str)
{
	while (get_safe_address(nm_otool, str))
	{
		if (!*str)
			return (true);
		str++;
	}
	return (false);
}