/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:08 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:30:09 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool	warning_log(char *message, char *file_name)
{
	ft_putstr_fd(WARNING_HEADER, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file_name, 2);
	return (false);
}
