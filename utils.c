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

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	store_cursor_position(t_fractal *fractal, t_point *cursor)
{
	mlx_get_mouse_pos(fractal->window, &(cursor->x), &(cursor->y));
	cursor->pos = from_mlx_to_complex(cursor->x, cursor->y, fractal);
}

uint32_t	color_set(double x, double y, t_fractal *fractal)
{
	int			iter;
	uint32_t	color;

	iter = create_set(x, y, fractal);
	if (iter < ITERATIONS)
		color = ft_pixel(iter * 4, iter * 2, iter * 3, 58);
	else
		color = ft_pixel(0, 0, 0, 58);
	return (color);
}

void	color_fractal(t_fractal *fractal)
{
	int				x;
	int				y;
	uint32_t		color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color = color_set(x, y, fractal);
			mlx_put_pixel(fractal->image, x, y, color);
			y++;
		}
		x++;
	}
}
