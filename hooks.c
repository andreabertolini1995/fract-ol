/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void color_fractal(void *param)
{
	uint32_t		x;
	uint32_t		y;
	uint32_t		color;
	t_fractal*		fractal;

	fractal = (t_fractal*) param;
	x = 0;
	while (x < fractal->image->width)
	{
		y = 0;
		while (y < fractal->image->height)
		{
			color = color_set(x, y, fractal->set, fractal->zoom);
			mlx_put_pixel(fractal->image, x, y, color);
			y++;
		}
		x++;
	}
}

/* This hook will control the zooming in and out of the fractal. */
void my_zoomhook(double xdelta, double ydelta, void* param)
{
	t_fractal*		fractal;

	fractal = (t_fractal*) param;
    fractal->zoom = fractal->zoom + ydelta;
	if (xdelta < 0)
		puts("Left!");
	else if (xdelta > 0)
		puts("Right!");
}

/* Hook to obtain the position (coordinates x and y) of the cursor. */
void my_cursorhook(double xpos, double ypos, void* param)
{
	param = NULL;
	printf("Xpos: %f\n", xpos);
	printf("Ypos:  %f\n", ypos);
}