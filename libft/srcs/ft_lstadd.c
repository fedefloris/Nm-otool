/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:28:02 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 19:07:50 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst != NULL)
	{
		if (*alst == NULL && new != NULL)
			*alst = new;
		else if (*alst != NULL && new != NULL)
		{
			tmp = *alst;
			*alst = new;
			(*new).next = tmp;
		}
	}
}
