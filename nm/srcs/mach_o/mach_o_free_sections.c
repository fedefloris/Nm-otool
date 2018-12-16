#include "nm_otool.h"
#include "nm.h"

bool				mach_o_free_sections(uint8_t **sections)
{
	free(sections);
	return (false);
}
