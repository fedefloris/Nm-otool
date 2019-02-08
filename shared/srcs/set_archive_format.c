/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_archive_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:50 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool			set_archive_format(t_nm_otool *nm_otool)
{
	if (!ft_strncmp(nm_otool->file.memory, ARMAG, SARMAG))
		nm_otool->file.format = ARCHIVE;
	else
		return (false);
	return (true);
}
