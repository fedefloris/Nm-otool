/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:30:48 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 15:38:29 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	void	*ft_mcpy(void const *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*s;
	size_t			i;

	dest = (unsigned char *)malloc(sizeof(*dest) * n + 1);
	if (dest != NULL)
	{
		s = (unsigned char *)src;
		i = 0;
		while (n-- > 0)
		{
			dest[i] = *s;
			i++;
			s++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new != NULL)
	{
		if (content == NULL)
		{
			(*new).content = NULL;
			(*new).content_size = 0;
		}
		else
		{
			(*new).content = ft_mcpy(content, content_size);
			(*new).content_size = content_size;
		}
		(*new).next = NULL;
	}
	return (new);
}
