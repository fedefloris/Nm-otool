#include <mach-o/fat.h>
#include <stdio.h>

#define SWAP_ENDIAN(x) (typeof(x))endian_swap((uint64_t)x, sizeof(x))
#define MAX_ENDIAN_SWAP_SIZE sizeof(uint64_t)

uint64_t			endian_swap(uint64_t value, size_t size)
{
	int				i;
	uint64_t		new_value;
	unsigned char	*new_tmp;
	unsigned char	*tmp;

	new_value = 0;
	new_tmp = (unsigned char *)&new_value;
	tmp = (unsigned char *)&value;
	if (size > MAX_ENDIAN_SWAP_SIZE || size == 1)
		return value;
	i = 0;
	while (--size)
	{
		new_tmp[i++] = tmp[size];
	}
	return (new_value);
}
