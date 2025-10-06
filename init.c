/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluz-ste <gluz-ste@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:52:29 by gluz-ste          #+#    #+#             */
/*   Updated: 2025/10/06 14:52:31 by gluz-ste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Memory allocation failed");
	exit(EXIT_FAILURE);
}

void	clean_exit(t_fractol *fractol)
{
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(EXIT_SUCCESS);
}

static void	init_img(t_fractol *fractol)
{
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
		clean_exit(fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
}

static void	init_events(t_fractol *fractol)
{
	mlx_hook(fractol->win, 17, 0, close_handler, fractol);
	mlx_hook(fractol->win, 2, 1L << 0, key_handler, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, mouse_handler, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		malloc_error();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!fractol->win)
		clean_exit(fractol);
	init_img(fractol);
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->max_iterations = MAX_ITERATIONS;
	init_events(fractol);
}
