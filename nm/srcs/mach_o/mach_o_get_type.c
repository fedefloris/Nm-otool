/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_o_get_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:25 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:27:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

static char			get_type_section(uint8_t n_sect, uint8_t **sections)
{
	if (sections[n_sect] && !ft_strcmp((char *)sections[n_sect], SECT_BSS))
		return ('B');
	if (sections[n_sect] && !ft_strcmp((char *)sections[n_sect], SECT_DATA))
		return ('D');
	if (sections[n_sect] && !ft_strcmp((char *)sections[n_sect], SECT_TEXT))
		return ('T');
	if (n_sect == NO_SECT)
		return ('?');
	return ('S');
}

char				mach_o_get_type(uint8_t n_type, uint64_t n_value,
		uint8_t n_sect, uint8_t **sections)
{
	char			type;

	type = '?';
	type = ((n_type & N_TYPE) == N_UNDF && n_value) ? 'C' : type;
	type = ((n_type & N_TYPE) == N_UNDF && !n_value) ? 'U' : type;
	type = ((n_type & N_TYPE) == N_ABS) ? 'A' : type;
	type = ((n_type & N_TYPE) == N_PBUD) ? 'U' : type;
	if ((n_type & N_TYPE) == N_SECT)
		type = get_type_section(n_sect, sections);
	type = ((n_type & N_TYPE) == N_INDR) ? 'I' : type;
	type = ((n_type & N_STAB) != 0) ? '-' : type;
	type += ((n_type & N_EXT) == 0 && type != '0' && type != '-') ? 32 : 0;
	return (type);
}
