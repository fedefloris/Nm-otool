/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_lmod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:44:05 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 19:46:13 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_isvalid_lmod(t_format *format)
{
	if (ft_strcmp((*format).lmod, "hh") != 0
			&& ft_strcmp((*format).lmod, "h") != 0
			&& ft_strcmp((*format).lmod, "l") != 0
			&& ft_strcmp((*format).lmod, "ll") != 0
			&& ft_strcmp((*format).lmod, "j") != 0
			&& ft_strcmp((*format).lmod, "z") != 0)
		return (FALSE);
	return (TRUE);
}
