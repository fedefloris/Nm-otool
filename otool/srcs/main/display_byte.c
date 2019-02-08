/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:49 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:30:50 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

static char			*get_formatted_byte(int byte)
{
	static char		formatted[3];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 2);
	if (!(number = ft_itoa_base(byte, 16)))
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
