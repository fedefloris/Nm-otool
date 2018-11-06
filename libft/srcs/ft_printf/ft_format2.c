/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:19:03 by jwong             #+#    #+#             */
/*   Updated: 2016/04/19 10:58:16 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_format_c(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	len = (*format).width - ft_strlen(fstr);
	if (ft_strcmp((*format).value_str, "\0") == 0)
		len -= 1;
	if (len > 0)
		ft_add_alignment_c(format, &fstr, len);
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	if (ft_strcmp((*format).value_str, "\0") == 0)
		ft_fill_buffer(info, "\0", 1);
	free(fstr);
	return (TRUE);
}

int		ft_format_s(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	if ((*format).value_str == NULL)
		return (FALSE);
	fstr = ft_strdup((*format).value_str);
	if ((*format).precision == 0 || (*format).precision == -2)
		fstr[0] = '\0';
	if ((int)ft_strlen(fstr) > (*format).precision && (*format).precision > 0)
		ft_add_precision_s(format, &fstr);
	if ((len = (*format).width - ft_strlen(fstr)) > 0)
		ft_add_alignment_c(format, &fstr, len);
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}

int		ft_format_p(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	if (ft_strcmp((*format).value_str, "0") == 0)
		if ((*format).precision == 0 || (*format).precision == -2)
			fstr[0] = '\0';
	if ((*format).precision > 0)
	{
		(*format).flag_zero = 0;
		ft_add_precision(format, &fstr);
	}
	if ((len = (*format).width - ft_strlen(fstr)) > 0)
		ft_add_alignment_p(format, &fstr, len, 'x');
	else
	{
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(&fstr, 'x');
	}
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}

int		ft_format_invalid_specifier(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	if ((*format).lmod != NULL)
		fstr[0] = '\0';
	if ((len = (*format).width - ft_strlen((*format).value_str)) > 0)
		return (ft_add_alignment_invalid(format, info, &fstr, len));
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}
