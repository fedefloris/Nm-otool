/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:50 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:27:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

bool			free_symbols(t_symbol *symbols)
{
	t_symbol		*tmp;

	while (symbols)
	{
		tmp = symbols;
		symbols = symbols->next;
		free(tmp);
	}
	return (false);
}
