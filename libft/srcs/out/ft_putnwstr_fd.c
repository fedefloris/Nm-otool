/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:13:25 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 13:14:41 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr_fd(const wchar_t *s, int fd, size_t n)
{
	long	i;

	i = (long)n;
	while (*s != L'\0')
	{
		i -= ft_wcharlen(*s);
		if (i < 0)
			break ;
		ft_putwchar_fd(*s, fd);
		s++;
	}
}
