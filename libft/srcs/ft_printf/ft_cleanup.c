/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 10:06:12 by jwong             #+#    #+#             */
/*   Updated: 2016/04/14 10:11:40 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cleanup(t_format *format)
{
	if ((*format).lmod != NULL)
		free((*format).lmod);
	if ((*format).value_str != NULL)
		free((*format).value_str);
}
