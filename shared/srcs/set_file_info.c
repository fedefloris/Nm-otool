/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:57 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:58 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool		set_file_info(t_nm_otool *nm_otool)
{
	if (set_archive_format(nm_otool))
		return (true);
	return (SET_FILE_INFO(nm_otool));
}
