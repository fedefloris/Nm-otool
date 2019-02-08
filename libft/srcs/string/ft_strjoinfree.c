/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:21:35 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/26 10:21:39 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *ret, char *s1, char *s2)
{
	char *str;

	if (!s1 && !s2)
		return (NULL);
	str = ft_strjoin(s1, s2);
	if (ret)
		free(ret);
	return (str);
}
