/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluz-ste <gluz-ste@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:52:36 by gluz-ste          #+#    #+#             */
/*   Updated: 2025/10/06 14:52:38 by gluz-ste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.r = z1.r + z2.r;
	result.i = z1.i + z2.i;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = 2 * z.r * z.i;
	return (result);
}

static double	parse_integer(char **s, int *sign)
{
	long	integer_part;

	integer_part = 0;
	while ((**s >= 9 && **s <= 13) || **s == 32)
		++(*s);
	while (**s == '+' || **s == '-')
		if (*(*s)++ == '-')
			*sign = -*sign;
	while (**s != '.' && **s)
		integer_part = (integer_part * 10) + (*(*s)++ - 48);
	return ((double)integer_part);
}

double	atodbl(char *s)
{
	double	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	integer_part = parse_integer(&s, &sign);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
