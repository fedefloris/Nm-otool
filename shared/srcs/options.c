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

/*
** Sets bits for alphanumeric characters.
** Sets left-most-bit in case of non-alphanumeric character
*/

static void			treat_option(char c, unsigned long *options)
{
	unsigned long	one;

	one = 1;
	if (c >= 'a' && c <= 'z')
		*options |= (one << (c - 97));
	else if (c >= 'A' && c <= 'Z')
		*options |= (one << (c - 39));
	else if (c >= '0' && c <= '9')
		*options |= (one << (c + 4));
	else
		*options |= (one << 63);
}

unsigned long		options(char ***argv)
{
	unsigned long	options;
	char			**tmp_argv;
	char			*str;

	options = 0;
	tmp_argv = *argv;
	if (tmp_argv)
		tmp_argv++;
	while (*tmp_argv)
	{
		str = *tmp_argv;
		if (!ft_strcmp(str, "--"))
		{
			tmp_argv++;
			break ;
		}
		else if (*str != '-')
			break ;
		else if (*str == '-')
		{
			str++;
			while (*str)
			{
				treat_option(*str, &options);
				str++;
			}
		}
		tmp_argv++;
	}
	*argv = tmp_argv;
	return (options);
}
