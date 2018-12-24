#include "nm_otool.h"
#include "otool.h"

static char	ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

static int	ft_get_len(uintmax_t num, uintmax_t base)
{
	int		len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

static char	*ft_generate_string(uintmax_t num, uintmax_t base, char c)
{
	uintmax_t	sum;
	int			mod;
	int			len;
	char		*str;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	sum = num;
	len = ft_get_len(num, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (sum)
	{
		mod = sum % base;
		sum /= base;
		str[(len--) - 1] = ft_calculate_char(mod, c);
	}
	return (str);
}
//Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
static char	*ft_itoa_base_tmp(uintmax_t num, uintmax_t base, char c)
{
	char	*str;

	str = ft_generate_string(num, base, c);
	return (str);
}

void		print_row(unsigned char *word)
{
	unsigned char	row[(WORD_NUM * 3) + 1];
	char			*number;
	int				i;
	int				j;

	i = 0;
	j = 0;
	number = NULL;
	while (j < WORD_NUM)
	{
		if ((number = ft_itoa_base_tmp(*word, 16, 'a')))//Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
		{
			if (ft_strlen(number) == 1)
				row[i++] = '0';
			ft_strcpy((char *)(row + i), number);
			i += ft_strlen(number);
		}
		else
			ft_strcpy((char *)(row + i), "00");

		row[i++] = ' ';
		j++;
		word++;
		ft_strdel(&number);
	}
	row[i] = '\0';
	ft_printf("%s", row);
}
