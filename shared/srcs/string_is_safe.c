#include "nm_otool.h"

bool		string_is_safe(t_nm_otool *nm_otool, char *str)
{
	if (!str)
		return (false);
	while (ADDRESS_IS_SAFE(str))
	{
		if (!*str)
			return (true);
		str++;
	}
	return (false);
}
