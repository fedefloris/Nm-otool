/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:40:09 by ffloris           #+#    #+#             */
/*   Updated: 2018/02/26 17:40:10 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **alst, void *content, int (*cmp)())
{
	t_list *last;
	t_list *curr;
	t_list *prev;

	last = NULL;
	prev = NULL;
	curr = *alst;
	while (curr)
	{
		if ((cmp && (*cmp)(curr->content, content) == 0) ||
			(curr->content == content))
		{
			if (*alst != curr)
				last->next = curr->next;
			else
				*alst = curr->next;
			prev = curr;
			curr = curr->next;
			free(prev);
			break ;
		}
		last = curr;
		curr = curr->next;
	}
}
