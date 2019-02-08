/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:54 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:30:55 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include "otool.h"

int				display_usage(void)
{
	ft_putstr("Usage: ./ft_otool [files]\n\n");
	ft_putstr("Object file displaying tool\n");
	return (EXIT_SUCCESS);
}
