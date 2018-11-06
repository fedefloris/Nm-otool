/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:37:28 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 15:33:17 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_putlnbr(long long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n / 10 == 0)
	{
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putlnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
}

void			ft_putnbr(int n)
{
	long long nbr;

	nbr = n;
	ft_putlnbr(nbr);
}
