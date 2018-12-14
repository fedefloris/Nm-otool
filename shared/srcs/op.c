#include "nm_otool.h"

bool		op(t_nm_otool *nm_otool, char c)
{
	return (option_check(nm_otool->options, c));
}
