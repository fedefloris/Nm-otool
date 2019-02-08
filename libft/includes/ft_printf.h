/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:44:17 by ffloris           #+#    #+#             */
/*   Updated: 2018/10/06 21:24:15 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# define CONVERT_FLAG "#"
# define ZEROS_FLAG "0"
# define LEFT_FLAG "-"
# define SIGN_FLAG "+"
# define SPACES_FLAG " "
# define WIDTH_NUMBER "w"
# define WIDTH_PARAM "*"
# define PRECISION_NUMBER "."
# define PRECISION_PARAM "*"
# define SHORT_LENGTH "h"
# define LONG_LENGTH "l"
# define INTMAX_LENGTH "j"
# define SIZE_T_LENGTH "z"
# define TYPE_STRING "s"
# define TYPE_WSTRING "S"
# define TYPE_POINTER "p"
# define TYPE_INT "d"
# define TYPE_INT_2 "i"
# define TYPE_LONG_INT "D"
# define TYPE_OCTAL "o"
# define TYPE_LONG_OCTAL "O"
# define TYPE_DECIMAL "u"
# define TYPE_LONG_DECIMAL "U"
# define TYPE_HEXA_DECIMAL "x"
# define TYPE_HEXA_DECIMAL_UPPERCASE "X"
# define TYPE_BINARY_DECIMAL "b"
# define TYPE_CHAR "c"
# define TYPE_WCHAR "C"
# define TYPE_CHARS_WRITTEN "n"
# define PUT_ID "%"
# define COLORS_ID "$"
# define END_COLORS_ID "$"
# define FD_ID "^"
# define END_FD_ID "^"
# define FD_PARAM "*"

typedef struct			s_printf
{
	const char			*s;
	int					fd;
	int					exit;
	int					index;
	va_list				*params;
	int					chrs_written;
}						t_printf;

typedef struct			s_fmt_ops
{
	t_printf			*tp;
	char				*type;
	int					convert;
	int					zeros;
	int					left;
	int					sign;
	int					spaces;
	int					width;
	int					precision;
	int					short_type;
	int					long_type;
	int					intmax_type;
	int					size_t_type;
}						t_fmt_ops;

typedef struct			s_nbr
{
	uintmax_t			nbr;
	uintmax_t			nbr_size;
	int					pos;
	int					space;
	int					neg;
	int					sign;
}						t_nbr;

typedef struct			s_fmt_type
{
	char				*id;
	void				(*put_type)(t_fmt_ops *ops);
}						t_fmt_type;

typedef struct			s_fmt
{
	char				*id;
	void				(*put)(t_printf *tp);
}						t_fmt;

extern t_fmt_type		g_types[];

void					setup_ops(t_printf *tp, t_fmt_ops *ops);
void					set_flags(t_fmt_ops *ops);
void					set_width(t_fmt_ops *ops);
void					set_precision(t_fmt_ops *ops);
void					set_length(t_fmt_ops *ops);

int						ft_printf_parse(t_printf *tp);
void					ft_printf_colors(t_printf *tp);
void					ft_printf_fd(t_printf *tp);
void					ft_printf_put(t_printf *tp);
void					ft_printf_putid(t_fmt_ops *ops);
void					ft_printf_putstr(t_fmt_ops *ops);
void					ft_printf_putwstr(t_fmt_ops *ops);
void					ft_printf_putchar(t_fmt_ops *ops);
void					ft_printf_putwchar(t_fmt_ops *ops);
void					ft_printf_putnbr(t_fmt_ops *ops);
void					ft_printf_putonbr(t_fmt_ops *ops);
void					ft_printf_puthexanbr(t_fmt_ops *ops);
void					ft_printf_putbinary(t_fmt_ops *ops);
void					ft_printf_putaddr(t_fmt_ops *ops);
void					ft_printf_chars_written(t_fmt_ops *ops);
uintmax_t				ft_printf_get_unbr_length(uintmax_t nbr,
														uintmax_t base);
void					ft_printf_put_uintmax_nbr(uintmax_t n, int fd,
									uintmax_t base, int hexa_uppercase);
uintmax_t				ft_printf_get_unbr(t_fmt_ops *ops);
uintmax_t				ft_printf_get_nbr(t_fmt_ops *ops, int *neg);

void					padding_with(t_fmt_ops *ops, size_t params_size,
														char value);
void					padding_with_prec(t_fmt_ops *ops, size_t params_size,
														char value);
void					add_padding(t_fmt_ops *ops, size_t params_size);
#endif
