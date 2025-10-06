/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluz-ste <gluz-ste@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:52:17 by gluz-ste          #+#    #+#             */
/*   Updated: 2025/10/06 14:52:19 by gluz-ste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	clean_exit(fractol);
	return (0);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == ESC_KEY)
		close_handler(fractol);
	return (0);
}

static void	zoom_at_point(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = map(x, fractol->min_r, fractol->max_r, WIDTH);
	mouse_i = map(y, fractol->min_i, fractol->max_i, HEIGHT);
	fractol->offset_x = mouse_r + (fractol->offset_x - mouse_r) / zoom_factor;
	fractol->offset_y = mouse_i + (fractol->offset_y - mouse_i) / zoom_factor;
	fractol->zoom *= zoom_factor;
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == MOUSE_WHEEL_UP)
	{
		zoom_at_point(fractol, x, y, 1.1);
		fractol_render(fractol);
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		zoom_at_point(fractol, x, y, 0.9);
		fractol_render(fractol);
	}
	return (0);
}
