/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:44 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/10 22:07:44 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	juliaset(t_fractal *julia)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	julia->x = 0;
	while (++julia->x <= julia->width)
	{
		julia->y = 0;
		while (++julia->y <= julia->height)
		{
			z0 = mappoint(julia, julia->x, julia->y);
			i = 1;
			while (i++ <= julia->iterations)
			{
				z1 = add(sqr(z0), julia->c);
				if (z1.x * z1.x + z1.y * z1.y > julia->radius * julia->radius)
				{
					my_mlx_pixel_put(julia, julia->x,
						julia->y, julia->color * i);
					break ;
				}
				z0 = z1;
			}
		}
	}
}
