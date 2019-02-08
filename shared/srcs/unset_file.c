/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:06 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:30:07 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include <sys/mman.h>

bool		unset_file(t_nm_otool *nm_otool)
{
	if (munmap(nm_otool->file.memory, nm_otool->file.size) < 0)
		return (WARNING_LOG("munmap call failed"));
	return (true);
}
