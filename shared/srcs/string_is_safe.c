/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_is_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:03 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:30:05 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool		string_is_safe(t_nm_otool *nm_otool, char *str)
{
	if (!str)
		return (false);
	while (ADDRESS_IS_SAFE(str))
	{
		if (!*(str++))
			return (true);
	}
	return (false);
}
