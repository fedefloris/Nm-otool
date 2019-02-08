/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:26 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:27 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char		*get_value_64(uint64_t value)
{
	static char		formatted[17];
	char			*number;
	int				formatted_index;
	int				number_index;

	ft_memset(formatted, '0', 16);
	if (!(number = ft_itoa_base(value, 16)))
		return ("");
	formatted_index = 15;
	if ((number_index = ft_strlen(number) - 1) > formatted_index)
		number_index = formatted_index;
	while (number_index >= 0)
		formatted[formatted_index--] = number[number_index--];
	ft_strdel(&number);
	return (formatted);
}
