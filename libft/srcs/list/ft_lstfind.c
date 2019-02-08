/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:32:08 by ffloris           #+#    #+#             */
/*   Updated: 2018/02/26 17:32:10 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfind(t_list *lst, void *content, int (*cmp)())
{
	if (!cmp)
		return (NULL);
	while (lst)
	{
		if (!cmp(lst->content, content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
