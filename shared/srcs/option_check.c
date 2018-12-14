#include "nm_otool.h"

bool		option_check(unsigned long options, char c)
{
	unsigned long	mask;

	mask = 1;
	if (c >= 'a' && c <= 'z')
		c -= 97;
	else if (c >= 'A' && c <= 'Z')
		c -= 39;
	else if (c >= '0' && c <= '9')
		c += 4;
	else
		return (false);
	mask <<= c;
	if ((options & mask) == mask)
		return (true);
	return (false);
}
