#include <mach-o/fat.h>
#include <stdio.h>

#define SWAP_ENDIAN(x) (typeof(x))endian_swap((uint64_t)x, sizeof(x))
#define MAX_ENDIAN_SWAP_SIZE sizeof(uint64_t)

static uint64_t		endian_swap(uint64_t value, int size)
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


int					main(void)
{
	uint8_t			x8 = 0xff;
	uint16_t		x16 = 0xff00;
	uint32_t		x32 = 0xff884400;
	uint64_t		x64 = 0xffaa997755331100;

	printf("%2x   %4x   %8x   %16llx\n", x8, x16, x32, x64);
	printf("%2x   %4x   %8x   %16llx\n", SWAP_ENDIAN(x8), SWAP_ENDIAN(x16), SWAP_ENDIAN(x32), SWAP_ENDIAN(x64));
	return (0);
}