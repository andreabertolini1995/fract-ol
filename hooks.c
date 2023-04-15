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
	
	// Assigning values to the reference system
	fractal->reference_system->pos->real = fractal->cursor_after_zoom->pos->real;
	fractal->reference_system->pos->imag = fractal->cursor_after_zoom->pos->imag;

	mlx_get_mouse_pos(fractal->window,
		&(fractal->cursor_before_zoom->x), &(fractal->cursor_before_zoom->y));
	fractal->cursor_before_zoom->pos = from_mlx_to_complex(fractal->cursor_before_zoom->x,
			fractal->cursor_before_zoom->y, fractal);
	if (ydelta > 0) // zoom out
	{
		fractal->zoom_type = OUT;
		fractal->zoom = fractal->zoom / ZOOM_FACTOR;
		fractal->number_zooms = 1 + fractal->number_zooms * ZOOM_FACTOR;
	}
	else if (ydelta < 0) // zoom in
	{
		fractal->zoom_type = IN;
		fractal->zoom = fractal->zoom * ZOOM_FACTOR;
		fractal->number_zooms = (fractal->number_zooms - 1) / ZOOM_FACTOR;
	}
	printf("Number of zooms: %f\n", fractal->number_zooms);
	printf("Zoom: %f\n", fractal->zoom);
	mlx_get_mouse_pos(fractal->window,
		&(fractal->cursor_after_zoom->x), &(fractal->cursor_after_zoom->y));
	fractal->cursor_after_zoom->pos = from_mlx_to_complex(fractal->cursor_after_zoom->x,
			fractal->cursor_after_zoom->y, fractal);
	fractal->num_zooms++;
	// printf("Reference system: %f + i%f\n", fractal->reference_system->pos->real, fractal->reference_system->pos->imag);
	// printf("Cursor before zoom: %f + %fi\n", fractal->cursor_before_zoom->pos->real, fractal->cursor_before_zoom->pos->imag);
	// printf("Cursor after zoom: %f + i%f\n", fractal->cursor_after_zoom->pos->real, fractal->cursor_after_zoom->pos->real);
	// printf("Diff real: %f\n", fractal->cursor_before_zoom->pos->real - fractal->reference_system->pos->real);
	// printf("Diff imag: %f\n\n", fractal->cursor_before_zoom->pos->imag - fractal->reference_system->pos->imag);
	if (xdelta < 0)
		printf("Left!");
	else if (xdelta > 0)
		printf("Right!");
}
