/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_middle_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:53 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:27:54 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

t_symbol		*get_middle_symbol(t_symbol *symbols)
{
	t_symbol *fast;
	t_symbol *slow;

	if (!symbols)
		return (NULL);
	slow = symbols;
	fast = symbols;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}
