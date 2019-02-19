/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colors.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:17:26 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/26 11:27:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_COLORS_H
# define FT_PRINTF_COLORS_H

# define RED_ID "red"
# define RED_VALUE "\e[31m"
# define BLACK_ID "black"
# define BLACK_VALUE "\e[30m"
# define GREEN_ID "green"
# define GREEN_VALUE "\e[32m"
# define YELLOW_ID "yellow"
# define YELLOW_VALUE "\e[33m"
# define BLUE_ID "blue"
# define BLUE_VALUE "\e[34m"
# define MAGENTA_ID "magenta"
# define MAGENTA_VALUE "\e[35m"
# define CYAN_ID "cyan"
# define CYAN_VALUE "\e[36m"
# define WHITE_ID "white"
# define WHITE_VALUE "\e[37m"
# define RESET_ID "reset"
# define RESET_VALUE "\e[0m"
# define EOC_ID "eoc"
# define EOC_VALUE "\e[0m"

typedef struct		s_color
{
	char			*id;
	char			*value;
}					t_color;

t_color				g_colors[] =
{
	{RED_ID, RED_VALUE},
	{BLACK_ID, BLACK_VALUE},
	{GREEN_ID, GREEN_VALUE},
	{YELLOW_ID, YELLOW_VALUE},
	{BLUE_ID, BLUE_VALUE},
	{MAGENTA_ID, MAGENTA_VALUE},
	{CYAN_ID, CYAN_VALUE},
	{WHITE_ID, WHITE_VALUE},
	{RESET_ID, RESET_VALUE},
	{EOC_ID, EOC_VALUE},
	{COLORS_ID, COLORS_ID},
	{NULL, NULL}
};

#endif
