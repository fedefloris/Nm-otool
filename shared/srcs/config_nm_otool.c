/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_nm_otool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:08 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:29:10 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool				config_nm_otool(t_nm_otool *nm_otool, char **argv,
	char **env, unsigned char routine)
{
	ft_bzero(nm_otool, sizeof(*nm_otool));
	if (!options(&argv,
		(routine == FT_NM) ? NM_OPTIONS : OTOOL_OPTIONS,
		&nm_otool->options))
		return (false);
	nm_otool->argv = argv;
	nm_otool->env = env;
	nm_otool->print_file_name = (*argv && *(argv + 1)) ? true : false;
	nm_otool->routine = routine;
	config_buffer(&nm_otool->buff);
	return (true);
}
