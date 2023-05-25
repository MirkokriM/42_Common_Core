/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:47:35 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/10 22:05:45 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_complex	mappoint(t_fractal *fractal, double x, double y)
{
	t_complex	c;
	double		l;

	if (fractal->width < fractal->height)
		l = fractal->height * fractal->zoom;
	else
		l = fractal->width * fractal->zoom;
	x += fractal->xarrow ;
	y += fractal->yarrow ;
	c.x = 2 * fractal->radius * (x - fractal->width / 2) / l;
	c.y = 2 * fractal->radius * (y - fractal->height / 2) / l;
	return (c);
}

void	wronginputs(void)
{
	ft_printf("Input Error!\nThis program only takes the ");
	ft_printf("parameters: \'julia\', \'mandelbrot\', /and ");
	ft_printf("\'tribrot\'with 480p, 720p or 2160p resolution.");
	ft_printf("You can display any of these fractal types!\n");
	ft_printf("When the window is open, press \'H\' for help!\n");
	exit(1);
}
