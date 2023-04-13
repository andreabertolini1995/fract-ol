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

t_complex	*initialize_complex(double real, double imag)
{
	t_complex	*compl;

	compl = malloc (sizeof(t_complex));
	if (compl == NULL)
		return (NULL);
	compl->real = real;
	compl->imag = imag;
	return (compl);
}

// void	initialize_cursor(t_fractal *fractal)
// {
// 	t_point		*cursor;

// 	cursor = malloc (sizeof(t_point));
// 	if (cursor == NULL)
// 		fractal->cursor = NULL;
// 	fractal->cursor = cursor;
// 	mlx_get_mouse_pos(fractal->window,
// 		&(fractal->cursor->x), &(fractal->cursor->y));
// 	fractal->cursor->pos = from_mlx_to_complex(fractal->cursor->x,
// 			fractal->cursor->y, fractal);
// 	printf("Mouse pos: %f + %fi\n", fractal->cursor->pos->real,
// 		fractal->cursor->pos->imag);
// }

t_point	*initialize_cursor()
{
	t_point		*cursor;

	cursor = malloc (sizeof(t_point));
	if (cursor == NULL)
		cursor = NULL;
	cursor->pos = initialize_complex(0,0);
	return (cursor);
}

t_fractal	*initialize_fractal(char *set)
{
	t_fractal	*fractal;

	fractal = malloc (sizeof(t_fractal));
	if (fractal == NULL)
		return (NULL);
	fractal->window = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->window)
		ft_error();
	fractal->image = mlx_new_image(fractal->window, WIDTH, HEIGHT);
	if (!fractal->image || (mlx_image_to_window(fractal->window,
				fractal->image, 0, 0) < 0))
		ft_error();
	fractal->set = set;
	fractal->zoom = 1;
	fractal->cursor_before_zoom = initialize_cursor();
	fractal->cursor_after_zoom = initialize_cursor();
	return (fractal);
}