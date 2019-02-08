/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:29:19 by dhojt             #+#    #+#             */
/*   Updated: 2019/02/08 11:29:20 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

bool	error_log(char *message, char *file_name)
{
	ft_putstr_fd(ERROR_HEADER, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file_name, 2);
	return (false);
}
