/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_is_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:03 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:30:05 by dhojt            ###   ########.fr       */
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
