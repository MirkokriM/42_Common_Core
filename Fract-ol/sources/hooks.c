/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:52:57 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/25 10:30:53 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_movement(int keycode, t_fractal *fractal)
{
	if (keycode == LEFT)
		fractal->xarrow -= 50;
	else if (keycode == DOWN)
		fractal->yarrow += 50;
	else if (keycode == RIGHT)
		fractal->xarrow += 50;
	else if (keycode == UP)
		fractal->yarrow -= 50;
	fractalsetup(fractal);
}

void	handle_zoom(int keycode, t_fractal *fractal)
{
	if (keycode == PLUS)
		fractal->iterations += 10;
	else if (keycode == MINUS)
		fractal->iterations -= 10;
	fractalsetup(fractal);
}

void	handle_color(int keycode, t_fractal *fractal)
{
	static const int	colors[] = {0xFF5733, 0x6B8E23, 0x7B241C,
		0x2980B9, 0x9B59B6, 0xE74C3C, 0xF1C40F, 0x2ECC71, 0x3498DB,
		0x8E44AD, 0xECF0F1, 0x1ABC9C, 0xFFFFFF, 0x00BDFF};
	static const int	num_colors = sizeof(colors) / sizeof(int);
	static int			current_color_index = 0;

	if (keycode == C)
	{
		current_color_index++;
		if (current_color_index == num_colors)
			current_color_index = 0;
		fractal->color = colors[current_color_index];
	}
	else if (keycode == X)
	{
		current_color_index--;
		if (current_color_index < 0)
			current_color_index = num_colors - 1;
		fractal->color = colors[current_color_index];
	}
}

int	key_hook(int keycode, t_fractal *fractal)
{
	static int	info_visible = 0;

	handle_color(keycode, fractal);
	handle_zoom(keycode, fractal);
	if (keycode == ESC)
		close_game(fractal);
	else if (keycode == R)
	{
		ft_printf("Reset Time!\n");
		reset_fractal(fractal);
	}
	else if (keycode == H)
	{
		if (info_visible)
			info_visible = 0;
		else
			info_visible = 1;
	}
	else if (keycode != ESC)
		handle_movement(keycode, fractal);
	draw_info(fractal, info_visible);
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	if (key_code == 1 && !ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->c.x = ((double)x / fractal->width * 4 - 2);
		fractal->c.y = ((double)y / fractal->height * 3 - 1.5);
		fractal->zoom = 1;
	}
	else if (key_code == 4)
		ft_zoom(((double)x / fractal->width * 1000 - 500),
			((double)y / fractal->height * 1000 - 500), fractal);
	else if (key_code == 5)
		ft_dezoom(((double)x / fractal->width * 1000 - 500),
			((double)y / fractal->height * 1000 - 500), fractal);
	fractalsetup(fractal);
	return (0);
}
