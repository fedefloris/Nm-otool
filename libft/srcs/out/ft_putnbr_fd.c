/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:21:21 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/17 18:24:51 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	unb = n;
	if (unb >= 10)
		ft_putnbr_fd(unb / 10, fd);
	ft_putchar_fd(unb % 10 + '0', fd);
}
