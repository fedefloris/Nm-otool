/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:19:04 by jwong             #+#    #+#             */
/*   Updated: 2016/04/20 15:47:27 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_get_wstring(int *num)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*ret;

	ret = ft_strdup("");
	i = 0;
	while (num[i] != 0)
	{
		tmp = ret;
		tmp2 = ft_get_wchar(num[i]);
		ret = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		i++;
	}
	return (ret);
}
