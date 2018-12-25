#include "nm_otool.h"
#include "otool.h"

bool				display_byte(t_nm_otool *nm_otool, unsigned char **byte,
				uint64_t *current_byte, uint64_t *position_on_row)
{
	if (!ADDRESS_IS_SAFE(*byte))
		return (ERROR_LOG("current row is beyond binary"));
	ft_printf("%02x ", **byte);
	if (!ADVANCE(*byte, *byte + sizeof(**byte)))
		return (ERROR_LOG("next byte is beyond binary"));
	*position_on_row += 1;
	*current_byte += 1;
	return (true);
}
