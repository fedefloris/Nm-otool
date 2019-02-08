/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:55:32 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/05 15:55:33 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*res_last;

	if (!lst || !f)
		return (NULL);
	res_last = f(lst);
	res = res_last;
	while (lst->next)
	{
		lst = lst->next;
		if (!(res_last->next = f(lst)))
			return (NULL);
		res_last = res_last->next;
	}
	return (res);
}
