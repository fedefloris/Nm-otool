/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:22 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:23 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char			*get_safe_address(t_nm_otool *nm_otool, char *address)
{
	if (address < nm_otool->file.memory
		|| address > nm_otool->file.end_of_file)
		return (NULL);
	return (address);
}
