/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:30 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:31 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static void	config_file(t_nm_otool *nm_otool, char *file_name)
{
	ft_bzero(&nm_otool->file, sizeof(nm_otool->file));
	nm_otool->file.name = file_name;
}

int			list_obj_symbols(t_nm_otool *nm_otool,
	char *file_name, t_obj_handler obj_handler)
{
	config_file(nm_otool, file_name);
	if (!set_file(nm_otool))
		return (EXIT_FAILURE);
	if (obj_handler && !obj_handler(nm_otool))
		return (EXIT_FAILURE);
	if (!unset_file(nm_otool))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
