/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:01:04 by jwong             #+#    #+#             */
/*   Updated: 2016/04/19 10:58:46 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define BUFF_SIZE 32

typedef struct	s_info
{
	va_list		ap;
	size_t		buff_len;
	size_t		char_count;
	char		*buffer;
}				t_info;

typedef struct	s_format
{
	char	flag_sharp	: 1;
	char	flag_zero	: 1;
	char	flag_minus	: 1;
	char	flag_space	: 1;
	char	flag_plus	: 1;
	char	is_zero		: 1;
	char	neg_sign	: 1;
	char	*lmod;
	char	*value_str;
	int		width;
	int		precision;
}				t_format;

/*
**	ft_add_sign.c
*/
void			ft_add_sign(t_format *format, char **fstr);
void			ft_sharp_handler(char **fstr, char c);

/*
**	ft_alignment1.c
*/
int				ft_add_alignment_di(t_format *format, char **fstr, int len);
int				ft_add_alignment_o(t_format *format, char **fstr, int len);
int				ft_add_alignment_x(t_format *format, char **fstr, int len,
				char c);
int				ft_add_alignment_u(t_format *format, char **fstr, int len);

/*
**	ft_alignment2.c
*/
int				ft_add_alignment_c(t_format *format, char **fstr, int len);
int				ft_add_alignment_p(t_format *format, char **fstr, int len,
		char c);
int				ft_add_alignment_invalid(t_format *format, t_info *info,
		char **fstr, int len);

void			ft_cleanup(t_format *format);
void			ft_fill_buffer(t_info *info, char *str, size_t n);
int				ft_fprintf(FILE *stream, const char *format, ...);

/*
**	ft_format1.c
*/
int				ft_format_di(t_info *info, t_format *format);
int				ft_format_o(t_info *info, t_format *format);
int				ft_format_percent(t_info *info, t_format *format);
int				ft_format_x(t_info *info, t_format *format, char c);
int				ft_format_u(t_info *info, t_format *format);

/*
**	ft_format2.c
*/
int				ft_format_c(t_info *info, t_format *format);
int				ft_format_invalid_specifier(t_info *info, t_format *format);
int				ft_format_p(t_info *info, t_format *format);
int				ft_format_s(t_info *info, t_format *format);

int				ft_format_processing(t_info *info, t_format *format, char c);
char			*ft_get_wchar(int num);
char			*ft_get_wstring(int *num);

int				ft_isvalid_lmod(t_format *format);

/*
**	ft_justified.c
*/
char			*ft_padding(int len, char c);
void			ft_left_adjust(char **fstr, int size);
void			ft_right_adjust(char **fstr, int size, char c);

/*
**	ft_precision_handling.c
*/
void			ft_add_precision(t_format *format, char **fstr);
void			ft_add_precision_s(t_format *format, char **fstr);

/*
**	ft_preformatting.c
*/
int				ft_get_format_string(t_info *info, char *str, int *i);
int				ft_get_formatted_string(t_info *info, char *str);
void			ft_get_options(t_format *format, char *s, int **i);

int				ft_printf(const char *format, ...);
char			*ft_remalloc(char *buffer, size_t len, size_t n);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

/*
**  ft_store_options.c
*/
int				ft_store_flags(t_format *format, char *s, int start);
int				ft_store_width(t_format *format, char *s, int start);
int				ft_store_precision(t_format *format, char *s, int start);
int				ft_store_lmod(t_format *format, char *s, char *str, int start);

/*
**	ft_specifiers1.c
*/
int				ft_specifier_cap_duo(t_info *info, t_format *format, char c);
int				ft_specifier_di(t_info *info, t_format *format);
int				ft_specifier_ox(t_info *info, t_format *format, char c);
int				ft_specifier_percent(t_format *format);
int				ft_specifier_u(t_info *info, t_format *format);

/*
**	ft_specifiers2.c
*/
int				ft_specifier_c(t_info *info, t_format *format, char c);
int				ft_specifier_invalid(t_format *format, char c);
int				ft_specifier_p(t_info *info, t_format *format);
int				ft_specifier_s(t_info *info, t_format *format, char c);

int				ft_vprintf(const char *format, va_list ap);
int				ft_vfprintf(FILE *stream, const char *format, va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size, const char *format,
		va_list ap);

#endif
