#include "nm_otool.h"

void	 swap_64(unsigned char word)
{
	unsigned char	tmp;
	unsigned char	new_word;
	int				i;

	i = 0;
	while (i < 4)
	{
		tmp = word & 3;
		new_word = new_word << 2;
		new_word |= tmp;
		word = word >> 2;
		i++;
	}
	//ft_printf("------->value = %.2x\n", y);
}

uint32_t    swap_endian(uint32_t value)
{
    uint32_t    result;
    uint32_t    byte1;
    uint32_t    byte2;
    uint32_t    byte3;
    uint32_t    byte4;

    byte1 = (value & 0xFF) << 24;
    byte2 = (value & 0xFF00) << 8;
    byte3 = (value & 0xFF0000) >> 8;
    byte4 = (value & 0xFF000000) >> 24;
    result = byte1 | byte2 | byte3 | byte4;
    return (result);
}
