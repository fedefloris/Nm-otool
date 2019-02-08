/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:27:36 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:27:38 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "nm.h"

static void		display_options(void)
{
	ft_putstr("\t-j\tDisplay only symbols values\n");
	ft_putstr("\t-p\tDo not sort the symbols\n");
	ft_putstr("\t-r\tReverse the sense of the sort\n");
}

int				display_usage(void)
{
	ft_putstr("Usage: ./ft_nm [options] [files]\n\n");
	ft_putstr("List object files symbols.\n\n");
	ft_putstr("The options are:\n");
	display_options();
	return (EXIT_SUCCESS);
}
