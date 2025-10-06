/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluz-ste <gluz-ste@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:51:37 by gluz-ste          #+#    #+#             */
/*   Updated: 2025/10/06 14:51:40 by gluz-ste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 60

# define MANDELBROT 1
# define JULIA 2

# define ESC_KEY 65307
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			fractal_type;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		kr;
	double		ki;
	int			max_iterations;
	double		zoom;
	double		offset_x;
	double		offset_y;
}	t_fractol;

/* Main functions */
int			main(int ac, char **av);
void		fractol_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);

/* Events */
int			key_handler(int keysym, t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			close_handler(t_fractol *fractol);

/* Math utilities */
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
double		atodbl(char *s);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/* String utilities */
void		putstr_fd(char *s, int fd);
int			strncmp(const char *s1, const char *s2, size_t n);

/* Color utilities */
int			interpolate(int start_color, int end_color, double t);
int			get_color(int i, int max_iterations);

/* Fractal calculations */
int			mandelbrot(t_complex c);
int			julia(t_complex z, t_complex c);

/* Memory management */
void		clean_exit(t_fractol *fractol);
void		malloc_error(void);

#endif
