#include "nm_otool.h"
#include "nm.h"

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

static char			*get_formatted_32_value(t_symbol *sym)
{
	static char		formatted[9];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 8);
	if (!(number = ft_itoa_base_tmp(sym->value, 16, 'a'))) // Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
		return ("");
	formatted_index = 7;
	if ((number_index = ft_strlen(number) - 1) > formatted_index)
		number_index = formatted_index;
	while (number_index >= 0)
		formatted[formatted_index--] = number[number_index--];
	ft_strdel(&number);
	return (formatted);
}

static char			*get_formatted_64_value(t_symbol *sym)
{
	static char		formatted[17];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 16);
	if (!(number = ft_itoa_base_tmp(sym->value, 16, 'a'))) // Get rid of this and use with your own ft_itoa_base (the one in our dev libft does not work)
		return ("");
	formatted_index = 15;
	if ((number_index = ft_strlen(number) - 1) > formatted_index)
		number_index = formatted_index;
	while (number_index >= 0)
		formatted[formatted_index--] = number[number_index--];
	ft_strdel(&number);
	return (formatted);
}

static void			display_64_symbol_value(t_nm_otool *nm_otool,
	t_symbol *sym, bool print_value)
{
	if (print_value)
		SEND_TO_BUFFER(get_formatted_64_value(sym), " ");
	else
		SEND_TO_BUFFER("                 ");
}

static void			display_32_symbol_value(t_nm_otool *nm_otool,
	t_symbol *sym, bool print_value)
{
	if (print_value)
		SEND_TO_BUFFER(get_formatted_32_value(sym), " ");
	else
		SEND_TO_BUFFER("         ");
}

static bool			should_the_value_be_printed(t_symbol *sym)
{
	if ((sym->type == 'u' || ft_tolower(sym->type) == 'i')
		&& sym->value)
		return (true);
	return (sym->type != 'w'
		&& ft_tolower(sym->type) != 'u'
		&& ft_tolower(sym->type) != 'i');
}

void				display_symbol(t_nm_otool *nm_otool, t_symbol *sym)
{
	bool			print_value;
	static char		type[3];

	if (!sym->name || !*sym->name)
		return ;
	if (op(nm_otool, 'j'))
	{
		SEND_TO_BUFFER(sym->name, "\n");
		return ;
	}
	type[0] = sym->type;
	type[1] = ' ';
	print_value = should_the_value_be_printed(sym);
	if (IS_MACH_O_32(nm_otool->file.format)
			|| IS_ELF_32(nm_otool->file.format))
		display_32_symbol_value(nm_otool, sym, print_value);
	else
		display_64_symbol_value(nm_otool, sym, print_value);
	SEND_TO_BUFFER(type, sym->name, "\n");
}
