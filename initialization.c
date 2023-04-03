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

t_complex *initialize_complex()
{
	t_complex	*compl;

	compl = malloc (sizeof(t_complex));
		if (compl == NULL)
			return (NULL);
	compl->real = 0;
	compl->imag = 0;
	return (compl);
}

t_cursor	*initialize_cursor()
{
	t_cursor		*cursor;

	cursor = malloc (sizeof(t_cursor));
	if (cursor == NULL)
		return (NULL);
	cursor->x = 0;
	cursor->y = 0;
	cursor->pos = initialize_complex();
	return (cursor);
}

t_fractal *initialize_fractal(char *set)
{
	t_fractal 		*fractal;

	fractal = malloc (sizeof(t_fractal));
	if (fractal == NULL)
		return (NULL);
	fractal->window = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->window)
		ft_error();
	fractal->image = mlx_new_image(fractal->window, WIDTH, HEIGHT);
	if (!fractal->image || (mlx_image_to_window(fractal->window, fractal->image, 0, 0) < 0))
		ft_error();
	fractal->set = set;
	fractal->zoom = 1;
	fractal->cursor = initialize_cursor();
	return (fractal);
}