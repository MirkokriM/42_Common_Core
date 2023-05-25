/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:11 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/10 21:55:27 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mini-libft/libft.h"
# include "../mini-libft/ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

# define ESC 65307
# define C 99
# define X 120
# define H 104
# define LEFT 65363
# define UP 65364
# define RIGHT 65361
# define DOWN 65362
# define R 114
# define Z 122
# define PLUS 65451
# define MINUS 65453
# define ONE 49
# define TWO 50
# define THREE 51

typedef struct imaginary {
	double	x;
	double	y;
}			t_complex;

t_complex	sqr(t_complex a);
t_complex	add(t_complex a, t_complex b);

typedef struct s_fractal {
	t_complex	c;
	void		*mlx;
	void		*win;
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
	int			max_iterations;
}				t_fractal;

t_complex	mappoint(t_fractal *julia, double x, double y);

void		juliaset(t_fractal *julia);
void		mandelbrotset(t_fractal *mandel);
void		tribrotset(t_fractal *tribrot);
void		fractalsetup(t_fractal *fractal);
void		mandelbrot_param(t_fractal *fractal, char *name);
void		julia_param(t_fractal *fractal, char *name);
void		tribrot_param(t_fractal *fractal, char *name);
void		reset_fractal(t_fractal *fractal);
void		handle_color(int keycode, t_fractal *fractal);
void		handle_zoom(int keycode, t_fractal *fractal);
void		handle_movement(int keycode, t_fractal *fractal);
void		wronginputs(void);
void		draw_info(t_fractal *fractal, int info_visible);
void		ft_zoom(double x, double y, t_fractal *fractal);
void		ft_dezoom(double x, double y, t_fractal *fractal);

int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int			close_game(t_fractal *fractal);
int			check_fractal_name(char *name);
int			freeall(t_fractal *fractal);
int			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
#endif