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

void	color_fractal(void *param)
{
	int				x;
	int				y;
	uint32_t		color;
	t_fractal		*fractal;

	fractal = (t_fractal *) param;
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

void	ft_keys_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (mlx_is_key_down(fractal->window, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->window);
	if (mlx_is_key_down(fractal->window, MLX_KEY_UP))
		fractal->image->instances[0].y -= 10;
	if (mlx_is_key_down(fractal->window, MLX_KEY_DOWN))
		fractal->image->instances[0].y += 10;
	if (mlx_is_key_down(fractal->window, MLX_KEY_LEFT))
		fractal->image->instances[0].x -= 10;
	if (mlx_is_key_down(fractal->window, MLX_KEY_RIGHT))
		fractal->image->instances[0].x += 10;
}

void	my_zoomhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	mlx_get_mouse_pos(fractal->window,
		&(fractal->cursor->x), &(fractal->cursor->y));
	fractal->cursor->pos = from_mlx_to_complex(fractal->cursor->x,
			fractal->cursor->y, fractal);
	printf("Mouse pos: %f + %fi\n", fractal->cursor->pos->real,
		fractal->cursor->pos->imag);
	if (ydelta > 0) // zoom out
		fractal->zoom = fractal->zoom / 0.9;
	else if (ydelta < 0) // zoom in
		fractal->zoom = fractal->zoom * 0.9;
	if (xdelta < 0)
		printf("Left!");
	else if (xdelta > 0)
		printf("Right!");
}