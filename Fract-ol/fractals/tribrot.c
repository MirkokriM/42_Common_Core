/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tribrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:20:42 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/10 23:20:42 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	apply_tribrot(t_fractal *tribrot, t_complex c, t_complex z, int i)
{
	double	scale;

	scale = 0.8;
	c.x *= scale;
	c.y *= scale;
	while (i < tribrot->iterations && (z.x * z.x + z.y * z.y) <= 4)
	{
		if (i % 2 == 0)
			z = sqr(z);
		else
			z = add(sqr(z), c);
		i++;
	}
	if (i != tribrot->iterations)
	{
		my_mlx_pixel_put(tribrot, tribrot->x,
			tribrot->y, tribrot->color + (i * 8));
	}
}

void	tribrotset(t_fractal *tribrot)
{
	int			i;
	t_complex	z;
	t_complex	c;

	tribrot->y = -1;
	while (++tribrot->y < tribrot->height)
	{
		tribrot->x = -1;
		while (++tribrot->x < tribrot->width)
		{
			z.x = 0;
			z.y = 0;
			c = mappoint(tribrot, tribrot->x, tribrot->y);
			i = 0;
			apply_tribrot(tribrot, c, z, i);
		}
	}
}
