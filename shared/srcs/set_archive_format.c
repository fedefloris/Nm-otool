/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_archive_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:50 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:51 by ffloris          ###   ########.fr       */
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
