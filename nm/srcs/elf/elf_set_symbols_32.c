/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_set_symbols_32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:12 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:27:14 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

static void		set_symbol_info(t_nm_otool *nm_otool,
	Elf32_Shdr *section_headers,
	Elf32_Sym *sym, t_elf_symbols_info *info)
{
	Elf32_Shdr *section_header;

	info->st_shndx = SWAP_ENDIAN(sym->st_shndx);
	info->st_info = SWAP_ENDIAN(sym->st_info);
	info->sh_flags = 0;
	info->sh_type = 0;
	info->sh_name = "";
	section_header = &section_headers[info->st_shndx];
	if (info->st_shndx != SHN_UNDEF
		&& STRUCT_IS_SAFE(section_header))
	{
		info->sh_flags = SWAP_ENDIAN(section_header->sh_flags);
		info->sh_type = SWAP_ENDIAN(section_header->sh_type);
		info->sh_name = info->header_str_section
			+ SWAP_ENDIAN(section_header->sh_name);
		if (!STRING_IS_SAFE(info->sh_name))
			info->sh_name = "";
	}
}

static bool		set_symbol(t_nm_otool *nm_otool,
	Elf32_Shdr *section_headers, Elf32_Sym *sym,
	t_elf_symbols_info *info)
{
	char	type;

	set_symbol_info(nm_otool, section_headers, sym, info);
	type = elf_get_type(info);
	if (ft_tolower(type) == 'a' && !sym->st_value)
		return (true);
	return (add_symbol(&info->symbols,
		SWAP_ENDIAN(sym->st_value), type,
		info->str_section + SWAP_ENDIAN(sym->st_name)));
}

bool			elf_set_symbols_32(t_nm_otool *nm_otool,
	Elf32_Shdr *section_headers, t_elf_symbols_info *info)
{
	uint32_t		symbols_count;
	Elf32_Xword		sh_size;
	Elf32_Sym		*sym;

	sh_size = SWAP_ENDIAN(section_headers[info->index].sh_size);
	symbols_count = sh_size / sizeof(Elf32_Sym);
	if (!(SET(sym, nm_otool->file.memory
		+ SWAP_ENDIAN(section_headers[info->index].sh_offset))))
		return (ERROR_LOG("not enough space for a symbol"));
	while (symbols_count--)
	{
		if (!STRUCT_IS_SAFE(sym))
			return (ERROR_LOG("not enough space for a symbol"));
		if (!STRING_IS_SAFE(info->str_section
			+ SWAP_ENDIAN(sym->st_name)))
			return (ERROR_LOG("symbol name outside string table"));
		if (!set_symbol(nm_otool, section_headers, sym, info))
			return (ERROR_LOG("failed while adding a symbol"));
		sym++;
	}
	return (true);
}
