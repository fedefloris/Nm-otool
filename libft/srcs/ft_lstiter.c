/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:29:51 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 18:56:40 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp = lst;
		while ((*tmp).next != NULL)
		{
			f(tmp);
			tmp = (*tmp).next;
		}
		f(tmp);
	}
}
