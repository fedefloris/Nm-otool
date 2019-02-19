/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:56:30 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:59:50 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	abs_double(double a)
{
	return (a >= 0) ? a : -a;
}

double			ft_sqrt(double a)
{
	double epsilon;
	double guess;

	guess = a;
	epsilon = 1e-15;
	while (abs_double(guess - a / guess) > epsilon * guess)
		guess = (a / guess + guess) / 2.0;
	return (guess);
}
