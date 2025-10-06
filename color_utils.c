/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluz-ste <gluz-ste@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:52:04 by gluz-ste          #+#    #+#             */
/*   Updated: 2025/10/06 14:52:07 by gluz-ste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	extract_rgb(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

int	interpolate(int start_color, int end_color, double t)
{
	int	start_rgb[3];
	int	end_rgb[3];
	int	result_rgb[3];

	extract_rgb(start_color, &start_rgb[0], &start_rgb[1], &start_rgb[2]);
	extract_rgb(end_color, &end_rgb[0], &end_rgb[1], &end_rgb[2]);
	result_rgb[0] = start_rgb[0] + (int)((end_rgb[0] - start_rgb[0]) * t);
	result_rgb[1] = start_rgb[1] + (int)((end_rgb[1] - start_rgb[1]) * t);
	result_rgb[2] = start_rgb[2] + (int)((end_rgb[2] - start_rgb[2]) * t);
	return ((result_rgb[0] << 16) | (result_rgb[1] << 8) | result_rgb[2]);
}

static void	init_colors(int *colors)
{
	colors[0] = 0x0B3D91;
	colors[1] = 0x2D5F9A;
	colors[2] = 0x4EA1D3;
	colors[3] = 0x7BD3E6;
	colors[4] = 0xB28BD8;
	colors[5] = 0x7A2F8E;
}

int	get_color(int i, int max_iterations)
{
	double	t;
	int		colors[6];
	int		segment;

	if (i == max_iterations)
		return (BLACK);
	init_colors(colors);
	t = (double)i / max_iterations;
	t = t * 5;
	segment = (int)t;
	t = t - segment;
	if (segment >= 5)
		return (colors[5]);
	return (interpolate(colors[segment], colors[segment + 1], t));
}
