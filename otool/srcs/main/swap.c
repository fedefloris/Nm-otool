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
