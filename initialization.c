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

t_point	*initialize_point(double real, double imag)
{
	t_point		*point;

	point = malloc (sizeof(t_point));
	if (point == NULL)
		point = NULL;
	point->pos = initialize_complex(real, imag);
	return (point);
}

t_cursor	*initialize_cursor(void)
{
	t_cursor		*cursor;

	cursor = malloc (sizeof(t_cursor));
	if (cursor == NULL)
		cursor = NULL;
	cursor->before_zoom = initialize_point(0, 0);
	cursor->after_zoom = initialize_point(0, 0);
	return (cursor);
}

t_zoom	*initialize_zoom(void)
{
	t_zoom		*zoom;
	
	zoom = malloc (sizeof(t_zoom));
	if (zoom == NULL)
		zoom = NULL;
	zoom->value = 1;
	zoom->shift = 0;
	zoom->type = START;
	return (zoom);
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
	fractal->cursor = initialize_cursor();
	fractal->zoom = initialize_zoom();
	fractal->set = set;
	return (fractal);
}
