/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:26 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

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

//Get rid of this and use with your own ft_itoa_base
//(the one in our dev libft does not work)

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

char		*get_value_64(uint64_t value)
{
	static char		formatted[17];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 16);
	// Get rid of this and use with your own ft_itoa_base
	//(the one in our dev libft does not work)
	if (!(number = ft_itoa_base_tmp(value, 16, 'a')))
		return ("");
	formatted_index = 15;
	if ((number_index = ft_strlen(number) - 1) > formatted_index)
		number_index = formatted_index;
	while (number_index >= 0)
		formatted[formatted_index--] = number[number_index--];
	ft_strdel(&number);
	return (formatted);
}
