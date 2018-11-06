/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:08:33 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 15:34:08 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_putlnbr_fd(long long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n / 10 == 0)
	{
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putlnbr_fd(n / 10, fd);
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	nbr = n;
	ft_putlnbr_fd(nbr, fd);
}
