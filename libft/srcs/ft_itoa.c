/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:35:03 by jwong             #+#    #+#             */
/*   Updated: 2015/12/14 15:24:55 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_storenbr(int n, int *i, char *s, int tok)
{
	char	c;

	if (n / 10 == 0)
	{
		if (tok == 1)
		{
			c = (n % 10) + '1';
			tok = 0;
		}
		else
			c = (n % 10) + '0';
		s[*i] = c;
		(*i)++;
	}
	else
	{
		ft_storenbr(n / 10, i, s, tok);
		c = (n % 10) + '0';
		s[*i] = c;
		(*i)++;
	}
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		tok;

	ret = (char *)malloc(sizeof(*ret) * 12);
	if (ret != NULL)
	{
		tok = 0;
		if (n == -2147483648)
		{
			tok = 1;
			n += 1000000000;
		}
		i = 0;
		if (n < 0)
		{
			ret[i] = '-';
			n *= -1;
			i++;
		}
		ft_storenbr(n, &i, ret, tok);
		ret[i] = '\0';
	}
	return (ret);
}
