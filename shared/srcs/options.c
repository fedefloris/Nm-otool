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
** char ***argv
** Takes pointer to argv
** After processing options, (external) argv is set to first real argument.
** note if "--" is detected, options processing stops and a pointer to the
** next address in argv is set externally.
**
** *valid_options
** Valid options should conain a string of valid options.
** For example, if valid options are -l -a -f:
** The valid options string should be set to "afl\0"
**
** unsigned long *options
** Pointer to options variable.
** Sets bits for alphanumeric characters.
** Sets left-most-bit in case of non-alphanumeric character
**
** return: bool
** return (true) if options were read successfully.
** return (false) if bad option is detected.
*/

static bool			option_is_valid(char *valid_options, char c)
{
	while (*valid_options)
	{
		if (c == *valid_options)
			return (true);
		valid_options++;
	}
	ft_putstr_fd("illegal option: [", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("]", 2);
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
