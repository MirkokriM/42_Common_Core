/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:28 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/10 22:05:08 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_fractal_name(char *name)
{
	if (!ft_strncmp(name, "julia", 5) && ft_strlen(name) == 5)
		return (1);
	else if (!ft_strncmp(name, "mandelbrot", 10) && ft_strlen(name) == 10)
		return (1);
	else if (!ft_strncmp(name, "tribrot", 7) && ft_strlen(name) == 7)
		return (1);
	return (0);
}

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	mandelbrot_param(t_fractal *fractal, char *name)
{
	fractal->iterations = 150;
	fractal->zoom = 0.5;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = -180;
	fractal->yarrow = -30;
	fractal->color = 0xCF6665;
	fractal->name = name;
}

void	julia_param(t_fractal *fractal, char *name)
{
	fractal->c.x = -0.7231;
	fractal->c.y = 0.27015;
	fractal->radius = 3;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = 0xa00a0a;
	fractal->name = name;
}

void	tribrot_param(t_fractal *fractal, char *name)
{
	fractal->radius = 3;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->zoom = 0.8;
	fractal->iterations = 150;
	fractal->color = 0xa00a0a;
	fractal->name = name;
}
