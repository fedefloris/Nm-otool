/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:32:58 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 11:29:47 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_fmt_type	g_types[] =
{
	{TYPE_STRING, &ft_printf_putstr},
	{TYPE_WSTRING, &ft_printf_putwstr},
	{TYPE_POINTER, &ft_printf_putaddr},
	{TYPE_INT, &ft_printf_putnbr},
	{TYPE_LONG_INT, &ft_printf_putnbr},
	{TYPE_INT_2, &ft_printf_putnbr},
	{TYPE_OCTAL, &ft_printf_putonbr},
	{TYPE_LONG_OCTAL, &ft_printf_putonbr},
	{TYPE_DECIMAL, &ft_printf_putnbr},
	{TYPE_LONG_DECIMAL, &ft_printf_putnbr},
	{TYPE_HEXA_DECIMAL, &ft_printf_puthexanbr},
	{TYPE_HEXA_DECIMAL_UPPERCASE, &ft_printf_puthexanbr},
	{TYPE_CHAR, &ft_printf_putchar},
	{TYPE_WCHAR, &ft_printf_putwchar},
	{TYPE_CHARS_WRITTEN, &ft_printf_chars_written},
	{TYPE_BINARY_DECIMAL, &ft_printf_putbinary},
	{PUT_ID, &ft_printf_putid},
	{NULL, NULL}
};
