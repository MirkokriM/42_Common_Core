/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:31 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/25 10:36:21 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "tribrot", 7))
		tribrotset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	exit(0);
}

int	check_res(char *res, t_fractal *fractal)
{
	int		width;
	int		height;

	if (!ft_strncmp(res, "2160p", 5) && !res[5])
	{
		width = 3840;
		height = 2160;
	}
	else if (!ft_strncmp(res, "720p", 4) && !res[4])
	{
		width = 1280;
		height = 720;
	}
	else if (!ft_strncmp(res, "480p", 4) && !res[4])
	{
		width = 858;
		height = 480;
	}
	else
		return (0);
	fractal->width = width;
	fractal->height = height;
	return (1);
}

int	parse_input(t_fractal *fractal, int argc, char **argv)
{
	if (!check_fractal_name(argv[1]))
		return (0);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot_param(fractal, argv[1]);
	else if (!ft_strncmp(argv[1], "julia", 5))
		julia_param(fractal, argv[1]);
	else if (!ft_strncmp(argv[1], "tribrot", 7))
		tribrot_param(fractal, argv[1]);
	else
		return (0);
	if (argc == 3 && !check_res(argv[2], fractal))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal.width = 1920;
	fractal.height = 1080;
	if (argc == 2 || argc == 3)
	{
		if (!parse_input(&fractal, argc, argv))
			wronginputs();
		fractal.mlx = mlx_init();
		fractal.win = mlx_new_window(fractal.mlx, fractal.width,
				fractal.height, fractal.name);
		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
		fractalsetup(&fractal);
		mlx_key_hook(fractal.win, key_hook, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
		wronginputs();
	return (0);
}
