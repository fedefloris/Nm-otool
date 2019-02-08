/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:31:30 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:31:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

void		print_file_name(t_nm_otool *nm_otool, char *current_file)
{
	if (IS_ARCHIVE(nm_otool->file.format))
	{
		if (!current_file)
			return ;
		SEND_TO_BUFFER(nm_otool->file.name, "(", current_file, "):\n");
	}
	else
		SEND_TO_BUFFER(nm_otool->file.name, ":\n");
}
