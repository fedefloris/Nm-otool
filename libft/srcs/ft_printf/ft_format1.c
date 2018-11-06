/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:10:24 by jwong             #+#    #+#             */
/*   Updated: 2016/04/14 10:19:36 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_format_di(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	if ((*format).neg_sign != 0)
		fstr = ft_strdup(&format->value_str[1]);
	else
		fstr = ft_strdup((*format).value_str);
	if (ft_strcmp(fstr, "0") == 0)
		if ((*format).precision == 0 || (*format).precision == -2)
			fstr[0] = '\0';
	if ((*format).precision > 0)
	{
		(*format).flag_zero = 0;
		ft_add_precision(format, &fstr);
	}
	len = (*format).width - ft_strlen(fstr);
	if ((*format).width > 0 && len > 0)
		ft_add_alignment_di(format, &fstr, len);
	else
		ft_add_sign(format, &fstr);
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}

int		ft_format_o(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	if ((*format).is_zero && ft_strcmp((*format).value_str, "0") == 0)
		if ((*format).precision == 0 || (*format).precision == -2
				|| ((*format).precision == -1 && (*format).flag_sharp != 0))
			fstr[0] = '\0';
	if ((*format).precision > 0)
	{
		(*format).flag_zero = 0;
		ft_add_precision(format, &fstr);
		if ((*format).flag_sharp != 0)
			(*format).flag_sharp = 0;
	}
	if ((len = (*format).width - ft_strlen(fstr)) > 0)
		ft_add_alignment_o(format, &fstr, len);
	else if (len <= 0)
	{
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(&fstr, 'o');
	}
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}

int		ft_format_x(t_info *info, t_format *format, char c)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	if ((*format).is_zero && ft_strcmp((*format).value_str, "0") == 0)
	{
		(*format).flag_sharp = 0;
		if ((*format).precision == -2 || (*format).precision == 0)
			fstr[0] = '\0';
	}
	if ((*format).precision > 0)
	{
		(*format).flag_zero = 0;
		ft_add_precision(format, &fstr);
	}
	if ((len = (*format).width - ft_strlen(fstr)) > 0)
		ft_add_alignment_x(format, &fstr, len, c);
	else
	{
		if ((*format).flag_sharp != 0)
			ft_sharp_handler(&fstr, c);
	}
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}

int		ft_format_u(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	if (ft_strcmp((*format).value_str, "0") == 0 && (*format).is_zero != 0)
		if ((*format).precision == 0 || (*format).precision == -2)
			fstr[0] = '\0';
	if ((*format).precision > 0)
	{
		(*format).flag_zero = 0;
		ft_add_precision(format, &fstr);
	}
	if ((len = (*format).width - ft_strlen(fstr)) > 0)
		ft_add_alignment_u(format, &fstr, len);
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}

int		ft_format_percent(t_info *info, t_format *format)
{
	char	*fstr;
	int		len;

	fstr = ft_strdup((*format).value_str);
	len = (*format).width - ft_strlen(fstr);
	if (len > 0)
		ft_add_alignment_c(format, &fstr, len);
	ft_fill_buffer(info, fstr, ft_strlen(fstr));
	free(fstr);
	return (TRUE);
}
