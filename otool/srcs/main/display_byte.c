/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:49 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:30:50 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

static char			ft_calculate_char(int mod, char c)
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

static int			ft_get_len(uintmax_t num, uintmax_t base)
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

static char			*ft_itoa_base_tmp(uintmax_t num, uintmax_t base, char c)
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

static char			*get_formatted_byte(int byte)
{
	static char		formatted[3];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 2);
	// Get rid of this and use with your own ft_itoa_base
	//(the one in our dev libft does not work)
	if (!(number = ft_itoa_base_tmp(byte, 16, 'a')))
		return ("");
	formatted_index = 1;
	if ((number_index = ft_strlen(number) - 1) > formatted_index)
		number_index = formatted_index;
	while (number_index >= 0)
		formatted[formatted_index--] = number[number_index--];
	ft_strdel(&number);
	return (formatted);
}

bool				display_byte(t_nm_otool *nm_otool, unsigned char **byte,
				uint64_t *index, uint64_t *position)
{
	if (!ADDRESS_IS_SAFE(*byte))
		return (ERROR_LOG("current row is beyond binary"));
	SEND_TO_BUFFER(get_formatted_byte(**byte), " ");
	if (!ADVANCE(*byte, *byte + sizeof(**byte)))
		return (ERROR_LOG("next byte is beyond binary"));
	*position += 1;
	*index += 1;
	return (true);
}
