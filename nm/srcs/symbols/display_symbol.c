/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:46 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:27:47 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

static void			display_64_symbol_value(t_nm_otool *nm_otool,
	t_symbol *sym, bool print_value)
{
	if (print_value)
		SEND_TO_BUFFER(get_value_64(sym->value), " ");
	else
		SEND_TO_BUFFER("                 ");
}

static void			display_32_symbol_value(t_nm_otool *nm_otool,
	t_symbol *sym, bool print_value)
{
	if (print_value)
		SEND_TO_BUFFER(get_value_32(sym->value), " ");
	else
		SEND_TO_BUFFER("         ");
}

static bool			should_the_value_be_printed(t_symbol *sym)
{
	if ((sym->type == 'u' || ft_tolower(sym->type) == 'i')
		&& sym->value)
		return (true);
	return (sym->type != 'w'
		&& ft_tolower(sym->type) != 'u'
		&& ft_tolower(sym->type) != 'i');
}

void				display_symbol(t_nm_otool *nm_otool, t_symbol *sym)
{
	bool			print_value;
	static char		type[3];

	if (!sym->name || !*sym->name)
		return ;
	if (op(nm_otool, 'j'))
	{
		SEND_TO_BUFFER(sym->name, "\n");
		return ;
	}
	type[0] = sym->type;
	type[1] = ' ';
	print_value = should_the_value_be_printed(sym);
	if (IS_MACH_O_32(nm_otool->file.format)
			|| IS_ELF_32(nm_otool->file.format))
		display_32_symbol_value(nm_otool, sym, print_value);
	else
		display_64_symbol_value(nm_otool, sym, print_value);
	SEND_TO_BUFFER(type, sym->name, "\n");
}
