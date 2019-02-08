/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:40 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool		option_check(unsigned long options, char c)
{
	unsigned long	mask;

	mask = 1;
	if (c >= 'a' && c <= 'z')
		c -= 97;
	else if (c >= 'A' && c <= 'Z')
		c -= 39;
	else if (c >= '0' && c <= '9')
		c += 4;
	else
		return (false);
	mask <<= c;
	return ((options & mask) == mask);
}
