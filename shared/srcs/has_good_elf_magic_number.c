/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_good_elf_magic_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:28 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:29 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool		has_good_elf_magic_number(Elf32_Ehdr *header)
{
	return (header->e_ident[EI_MAG0] == ELFMAG0
		&& header->e_ident[EI_MAG1] == ELFMAG1
		&& header->e_ident[EI_MAG2] == ELFMAG2
		&& header->e_ident[EI_MAG3] == ELFMAG3);
}
