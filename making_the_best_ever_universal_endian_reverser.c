#include <mach-o/fat.h>
#include <stdio.h>

void				swap_endian(unsigned char *value, int size)
{
	int				i;
	unsigned char	tmp;
	i = 0;
	while (i < --size)
	{
		tmp = value[i];
		value[i] = value[size];
		value[size] = tmp;
		i++;
	}
}

int					main(void)
{
	uint8_t			x8 = 0xff;
	uint16_t		x16 = 0xff00;
	uint32_t		x32 = 0xff884400;
	uint64_t		x64 = 0xffaa997755331100;

	printf("%2x   %4x   %8x   %16llx\n", x8, x16, x32, x64);
	swap_endian((unsigned char *)&x8, sizeof(x8));
	swap_endian((unsigned char *)&x16, sizeof(x16));
	swap_endian((unsigned char *)&x32, sizeof(x32));
	swap_endian((unsigned char *)&x64, sizeof(x64));
	printf("%2x   %4x   %8x   %16llx\n", x8, x16, x32, x64);
	return (0);
}