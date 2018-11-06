/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:25:01 by jwong             #+#    #+#             */
/*   Updated: 2016/04/13 19:25:33 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_remalloc(char *buffer, size_t len, size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(*tmp) * size);
	if (tmp != NULL)
		tmp = (char *)ft_memcpy(tmp, buffer, len);
	return (tmp);
}
