/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:04:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:58:27 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*merge(t_list *node1, t_list *node2, int (*cmp)())
{
	t_list	head;
	t_list	*curr;

	curr = &head;
	while (node1 && node2)
	{
		if (cmp(node1->content, node2->content) <= 0)
		{
			curr->next = node1;
			node1 = node1->next;
		}
		else
		{
			curr->next = node2;
			node2 = node2->next;
		}
		curr = curr->next;
	}
	curr->next = (!node1) ? node2 : node1;
	return (head.next);
}

static t_list	*sort(t_list *head, int (*cmp)())
{
	t_list	*middle;
	t_list	*after_middle;

	if (!head || !head->next)
		return (head);
	middle = ft_lstmiddle(head);
	after_middle = middle->next;
	middle->next = NULL;
	return (merge(sort(head, cmp), sort(after_middle, cmp), cmp));
}

void			ft_lstsort(t_list **lst, int (*cmp)())
{
	if (!lst || !cmp)
		return ;
	*lst = sort(*lst, cmp);
}
