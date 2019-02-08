/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_row.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:52 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:30:53 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

static void			print_row(t_nm_otool *nm_otool, unsigned char *byte)
{
	unsigned char	row[PRINT_ROW_SIZE];
	char			*number;
	int				row_index;
	int				position;

	row_index = 0;
	position = 0;
	number = NULL;
	while (position < BYTES_PER_ROW)
	{
		if ((number = ft_itoa_base(byte[position], 16)))
		{
			if (ft_strlen(number) == 1)
				row[row_index++] = '0';
			ft_strcpy((char *)(row + row_index), number);
			row_index += ft_strlen(number);
		}
		else
			ft_strcpy((char *)(row + row_index), "00");
		row[row_index++] = ' ';
		position++;
		ft_strdel(&number);
	}
	row[row_index] = '\0';
	SEND_TO_BUFFER(row);
}

bool				display_row(t_nm_otool *nm_otool, unsigned char **byte,
				uint64_t *index, uint64_t *position)
{
	if (!ADDRESS_IS_SAFE(*byte + (BYTES_PER_ROW - 1)))
		return (ERROR_LOG("current row is beyond binary"));
	print_row(nm_otool, *byte);
	if (!ADVANCE(*byte, *byte + BYTES_PER_ROW))
		return (ERROR_LOG("next row is beyond binary"));
	*position += BYTES_PER_ROW;
	*index += BYTES_PER_ROW;
	return (true);
}
