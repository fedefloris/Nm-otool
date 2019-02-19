/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:52:43 by ffloris           #+#    #+#             */
/*   Updated: 2018/02/26 16:52:45 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*next;
	t_list	*prev;
	t_list	*actual;

	if (!lst)
		return ;
	actual = *lst;
	prev = NULL;
	while (actual)
	{
		next = actual->next;
		actual->next = prev;
		prev = actual;
		actual = next;
	}
	*lst = prev;
}
