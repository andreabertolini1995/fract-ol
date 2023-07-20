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

void	zoom_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	store_cursor_position(fractal, fractal->cursor->before_zoom);
	if (ydelta > 0)
	{
		fractal->zoom->type = OUT;
		fractal->zoom->value = fractal->zoom->value / ZOOM_FACTOR;
		fractal->zoom->shift = 1 + fractal->zoom->shift * ZOOM_FACTOR;
	}
	else if (ydelta < 0)
	{
		fractal->zoom->type = IN;
		fractal->zoom->value = fractal->zoom->value * ZOOM_FACTOR;
		fractal->zoom->shift = (fractal->zoom->shift - 1) / ZOOM_FACTOR;
	}
	store_cursor_position(fractal, fractal->cursor->after_zoom);
	color_fractal(fractal);
	(void) xdelta;
	(void) xdelta;
}

void	keys_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (mlx_is_key_down(fractal->window, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->window);
}
