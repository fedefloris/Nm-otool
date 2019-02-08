/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:48 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:27:49 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

void			display_symbols(t_nm_otool *nm_otool, t_symbol *symbols)
{
	if (nm_otool->print_file_name)
		SEND_TO_BUFFER("\n", nm_otool->file.name, ":\n");
	while (symbols)
	{
		display_symbol(nm_otool, symbols);
		symbols = symbols->next;
	}
	empty_the_buffer(&nm_otool->buff);
}
