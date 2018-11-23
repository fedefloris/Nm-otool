/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:31:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/09/02 09:22:37 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

/*
** Sets bits for alphanumeric characters.
** Sets left-most-bit in case of non-alphanumeric character
*/
static bool			option_is_valid(char *valid_options, char c)
{
	while (*valid_options)
	{
		if (c == *valid_options)
			return (true);
		valid_options++;
	}
	ft_putendl("BAD OPTION");
	return (false);
}

static bool			treat_option(char c, char *valid_options, unsigned long *options)
{
	unsigned long	one;

	if (!option_is_valid(valid_options, c))
		return (false);
	one = 1;
	if (c >= 'a' && c <= 'z')
		*options |= (one << (c - 97));
	else if (c >= 'A' && c <= 'Z')
		*options |= (one << (c - 39));
	else if (c >= '0' && c <= '9')
		*options |= (one << (c + 4));
	else
		*options |= (one << 63);
	return (true);
}

bool				options(char ***argv, char *valid_options, unsigned long *options)
{
	char			**tmp_argv;
	char			*str;

	*options = 0;
	tmp_argv = *argv;
	if (tmp_argv)
		tmp_argv++;
	while ((str = *tmp_argv))
	{
		if (!ft_strcmp(str, "--"))
		{
			tmp_argv++;
			break ;
		}
		else if (*str != '-')
			break ;
		else if (*str == '-')
		{
			while (*(++str))
				if (!treat_option(*str, valid_options, options))
					return (false);
		}
		tmp_argv++;
	}
	*argv = tmp_argv;
	return (true);
}
