/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_parse_section_header_64.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:05 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:27:06 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

bool		elf_parse_section_header_64(t_nm_otool *nm_otool,
	Elf64_Shdr *section_headers,
	t_elf_symbols_info *info)
{
	Elf64_Word	sh_type;

	sh_type = SWAP_ENDIAN(section_headers[info->index].sh_type);
	if (sh_type == SHT_SYMTAB)
	{
		if (!elf_set_symbols_64(nm_otool, section_headers, info))
			return (free_symbols(info->symbols));
		sort_symbols(nm_otool, &info->symbols);
		display_symbols(nm_otool, info->symbols);
		free_symbols(info->symbols);
	}
	return (true);
}
