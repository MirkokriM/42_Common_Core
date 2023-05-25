/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:43:57 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/10 12:43:57 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_zoom(double x, double y, t_fractal *fractal)
{
	fractal->x = (x / fractal->zoom) - (x / (fractal->zoom * 1.3));
	fractal->y = (y / fractal->zoom) - (y / (fractal->zoom * 1.3));
	fractal->zoom *= 1.3;
}

void	ft_dezoom(double x, double y, t_fractal *fractal)
{
	fractal->x = (x / fractal->zoom) - (x / (fractal->zoom / 1.3));
	fractal->y = (y / fractal->zoom) - (y / (fractal->zoom / 1.3));
	fractal->zoom /= 1.3;
}

int	close_game(t_fractal *fractal)
{
	freeall(fractal);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	reset_fractal(t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "julia") == 0)
		julia_param(fractal, fractal->name);
	else if (ft_strcmp(fractal->name, "mandelbrot") == 0)
		mandelbrot_param(fractal, fractal->name);
	else if (ft_strcmp(fractal->name, "tribrot") == 0)
		tribrot_param(fractal, fractal->name);
	fractalsetup(fractal);
}

void	draw_info(t_fractal *fractal, int info_visible)
{
	char	*it;
	char	*it_str;

	if (!info_visible)
		return ;
	mlx_set_font(fractal->mlx, fractal->win, "8x13bold");
	mlx_string_put(fractal->mlx, fractal->win, 10, 18, 0xFFFFFF, "User key:");
	mlx_string_put(fractal->mlx, fractal->win, 10, 38,
		0xFFFFFF, "ESC key: exit");
	mlx_string_put(fractal->mlx, fractal->win, 10, 58,
		0xFFFFFF, "Arrow key: move");
	mlx_string_put(fractal->mlx, fractal->win, 10, 78,
		0xFFFFFF, "+/-: in-de/crase iteration");
	mlx_string_put(fractal->mlx, fractal->win, 10, 98,
		0xFFFFFF, "C/X: change color");
	mlx_string_put(fractal->mlx, fractal->win, 10, 118,
		0xFFFFFF, "R: reset view");
	it = ft_itoa(fractal->iterations);
	it_str = ft_strjoin("Iterazioni: ", it);
	mlx_string_put(fractal->mlx, fractal->win, 7, 138,
		0xFFFFFF, it_str);
	free(it);
	free(it_str);
}
