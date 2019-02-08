/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_objs_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:32 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:33 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int		list_objs_symbols(t_nm_otool *nm_otool, t_obj_handler obj_handler)
{
	int				exit_status;
	char			**argv;

	argv = nm_otool->argv;
	exit_status = EXIT_SUCCESS;
	while (*argv)
	{
		if (list_obj_symbols(nm_otool, *argv, obj_handler) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
		argv++;
	}
	return (exit_status);
}
