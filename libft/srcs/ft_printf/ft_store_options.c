/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:23:21 by jwong             #+#    #+#             */
/*   Updated: 2016/04/21 18:57:07 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_store_flags(t_format *format, char *s, int start)
{
	int	len;

	len = 0;
	while (s[start] && (s[start] == '#' || s[start] == '0' || s[start] == '-'
				|| s[start] == ' ' || s[start] == '+'))
	{
		if (s[start] == '#')
			(*format).flag_sharp = 1;
		else if (s[start] == '0')
			(*format).flag_zero = 1;
		else if (s[start] == '-')
			(*format).flag_minus = 1;
		else if (s[start] == ' ')
			(*format).flag_space = 1;
		else if (s[start] == '+')
			(*format).flag_plus = 1;
		start++;
		len++;
	}
	if ((*format).flag_minus != 0)
		(*format).flag_zero = 0;
	if ((*format).flag_plus != 0)
		(*format).flag_space = 0;
	return (len);
}

static int	get_len(char *s, int start)
{
	int	len;
	int	i;

	len = 0;
	i = start;
	while (s[i] && (ft_isdigit((int)s[i]) == 1))
	{
		len++;
		i++;
	}
	return (len);
}

int			ft_store_width(t_format *format, char *s, int start)
{
	char	*num;
	int		len;

	if ((len = get_len(s, start)) == 0)
		return (0);
	if ((num = ft_strsub(s, start, len)))
	{
		(*format).width = ft_atoi(num);
		free(num);
	}
	return (len);
}

int			ft_store_precision(t_format *format, char *s, int start)
{
	char	*num;
	int		len;

	if (s[start++] != '.')
		return (0);
	if ((len = get_len(s, start)) == 0)
	{
		(*format).precision = -2;
		return (1);
	}
	if ((num = ft_strsub(s, start, len)))
	{
		(*format).precision = ft_atoi(num);
		if ((*format).precision < 0)
			(*format).precision = -1;
		free(num);
	}
	return (len + 1);
}

int			ft_store_lmod(t_format *format, char *s, char *str, int start)
{
	if (ft_strncmp(s, "hh", 2) == 0)
	{
		(*format).lmod = ft_strdup("hh");
		return (2);
	}
	else if (ft_strncmp(s, "ll", 2) == 0)
	{
		(*format).lmod = ft_strdup("ll");
		return (2);
	}
	else if (str[start] == 'h' && str[start + 1] != 'h')
	{
		(*format).lmod = ft_strdup("h");
		return (1);
	}
	else if ((str[start] == 'l' && str[start + 1] != 'l')
			|| str[start] == 'j' || str[start] == 'z')
	{
		(*format).lmod = ft_strdup("j");
		return (1);
	}
	return (0);
}
