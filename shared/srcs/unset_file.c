/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:06 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:30:07 by ffloris          ###   ########.fr       */
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
