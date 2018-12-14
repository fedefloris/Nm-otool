#include "nm_otool.h"

uint64_t			endian_swap(uint64_t value,
		size_t size, bool endian_is_reversed)
{
	uint64_t		new_value;
	unsigned char	*new_tmp;
	unsigned char	*tmp;
	int				i;

	if (!endian_is_reversed || size > MAX_ENDIAN_SWAP_SIZE)
		return (value);
	new_value = 0;
	new_tmp = (unsigned char *)&new_value;
	tmp = (unsigned char *)&value;
	i = 0;
	while (--size)
		new_tmp[i++] = tmp[size];
	new_tmp[i++] = tmp[size];
	return (new_value);
}
