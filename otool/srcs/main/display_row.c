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

//Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
static char	*ft_itoa_base_tmp(uintmax_t num, uintmax_t base, char c)
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

static void			print_row(unsigned char *byte)
{
	unsigned char	row[(BYTES_PER_ROW * 3) + 1];
	char			*number;
	int				row_index;
	int				position_on_row;

	row_index = 0;
	position_on_row = 0;
	number = NULL;
	while (position_on_row < BYTES_PER_ROW)
	{
		if ((number = ft_itoa_base_tmp(byte[position_on_row], 16, 'a')))//Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
		{
			if (ft_strlen(number) == 1)
				row[row_index++] = '0';
			ft_strcpy((char *)(row + row_index), number);
			row_index += ft_strlen(number);
		}
		else
			ft_strcpy((char *)(row + row_index), "00");
		row[row_index++] = ' ';
		position_on_row++;
		ft_strdel(&number);
	}
	row[row_index] = '\0';
	ft_printf("%s", row);
}

bool				display_row(t_nm_otool *nm_otool, unsigned char **byte,
				uint64_t *current_byte, uint64_t *position_on_row)
{
	if (!ADDRESS_IS_SAFE(*byte + (BYTES_PER_ROW - 1)))
		return (ERROR_LOG("current row is beyond binary"));
	print_row(*byte);
	if (!ADVANCE(*byte, *byte + BYTES_PER_ROW))
		return (ERROR_LOG("next row is beyond binary"));
	*position_on_row += BYTES_PER_ROW;
	*current_byte += BYTES_PER_ROW;
	return (true);
}
