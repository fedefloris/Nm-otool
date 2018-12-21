#include "nm_otool.h"

bool		string_is_safe(t_nm_otool *nm_otool, char *str)
{
	if (!str)
		return (false);
	while (get_safe_address(nm_otool, str))
	{
		if (!*str)
			return (true);
		if (!ft_isprint(*str))
			return (false);
		str++;
	}
	return (false);
}
