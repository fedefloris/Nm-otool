/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:51:41 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/30 16:14:21 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *a, int start, int end)
{
	int	pivot;
	int	i;

	i = start;
	pivot = start - 1;
	while (i < end - 1)
	{
		if (a[i] <= a[end])
		{
			pivot++;
			ft_swap(a + pivot, a + i);
		}
		i++;
	}
	ft_swap(a + pivot + 1, a + end);
	return (pivot + 1);
}

static void	quicksort(int *a, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(a, start, end);
		quicksort(a, start, pivot - 1);
		quicksort(a, pivot + 1, end);
	}
}

void		ft_quicksort(int *a, int a_size)
{
	if (!a || a_size <= 1)
		return ;
	quicksort(a, 0, a_size - 1);
}
