/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:18:27 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 18:57:49 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*head;
	t_list	*new;
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp = lst;
		new = f(tmp);
		head = new;
		tmp = (*tmp).next;
		while (tmp != NULL)
		{
			(*new).next = f(tmp);
			tmp = (*tmp).next;
			new = (*new).next;
		}
		(*new).next = NULL;
		return (head);
	}
	return (NULL);
}
