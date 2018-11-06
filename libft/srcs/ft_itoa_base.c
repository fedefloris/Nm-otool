/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:36:40 by jwong             #+#    #+#             */
/*   Updated: 2016/04/04 16:50:31 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_total_digits(unsigned long nb, unsigned int base)
{
	unsigned int	len;

	len = 0;
	while ((nb / base) > 0)
	{
		len++;
		nb /= base;
	}
	return (len + 1);
}

static void			ft_storenb(unsigned long nb, char *base, int *i, char *s)
{
	int len;

	len = ft_strlen(base);
	if ((nb / len) == 0)
	{
		s[*i] = base[(nb % len)];
		(*i)++;
		s[*i] = '\0';
	}
	else
	{
		ft_storenb((nb / len), base, i, s);
		s[*i] = base[(nb % len)];
		(*i)++;
		s[*i] = '\0';
	}
}

char				*ft_itoa_base(unsigned long nb, char *base)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(base);
	ret = (char *)malloc(sizeof(*ret) * (ft_total_digits(nb, len) + 1));
	if (ret != NULL)
	{
		i = 0;
		ft_storenb(nb, base, &i, ret);
	}
	return (ret);
}

char				*ft_itoa_base_signed(long nb, char *base)
{
	char	*ret;
	char	*tmp;

	if (nb < 0)
	{
		ret = ft_itoa_base((nb * -1), base);
		tmp = ret;
		ret = ft_strjoin("-", ret);
		free(tmp);
		return (ret);
	}
	return (ft_itoa_base(nb, base));
}
