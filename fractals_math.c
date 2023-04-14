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

t_complex	*from_mlx_to_complex(double x, double y, t_fractal *fractal)
{
	t_complex	*num;

	num = malloc (sizeof(t_complex));
	if (num == NULL)
		return (NULL);
	num->real = (-1 + 2 * (x / WIDTH)) * WIDTH / HEIGHT * fractal->zoom;
	num->imag = (1 - 2 * (y / HEIGHT)) * fractal->zoom;
	return (num);
}

static t_complex	*move_fractal(t_complex *num, t_fractal *fractal)
{
	double diff_x;
	double diff_y;

	diff_x = fractal->cursor_after_zoom->pos->real - fractal->cursor_before_zoom->pos->real;
	diff_y = fractal->cursor_after_zoom->pos->imag - fractal->cursor_before_zoom->pos->imag;
	if (fractal->zoom_type == OUT)
	{
		num->real = num->real - fractal->number_zooms * diff_x;
		num->imag = num->imag - fractal->number_zooms * diff_y;
		
	}
	else if (fractal->zoom_type == IN)
	{
		num->real = num->real + (ZOOM_FACTOR * fractal->number_zooms) * diff_x;
		num->imag = num->imag + (ZOOM_FACTOR * fractal->number_zooms) * diff_y;
	}
	return (num);
}

int from_real_to_mlx(double real)
{
	int x;

	x = (real + 1) * WIDTH/2;
	return (x);
}

int from_imag_to_mlx(double imag)
{
	int y;

	y = ((1 - imag)) * HEIGHT / 2;
	return (y);
}

int	check_stability(t_complex *z, t_complex *c)
{
	t_complex	*tmp;
	int			i;

	tmp = malloc (sizeof(t_complex));
	if (tmp == NULL)
		return (0);
	i = 0;
	while (i < ITERATIONS)
	{
		tmp->real = (z->real * z->real - z->imag * z->imag) + c->real;
		tmp->imag = (2 * z->real * z->imag) + c->imag;
		z->real = tmp->real;
		z->imag = tmp->imag;
		if (z->real == INFINITY || z->imag == INFINITY
			|| !(z->real == z->real) || !(z->imag == z->imag))
			return (i);
		i++;
	}
	free(tmp);
	return (i);
}

int	create_set(double x, double y, t_fractal *fractal)
{
	t_complex	*z;
	t_complex	*c;
	int			iterations;

	z = malloc (sizeof(t_complex));
	if (z == NULL)
		return (0);
	if (!strncmp(fractal->set, "mandelbrot", strlen(fractal->set)))
	{
		c = from_mlx_to_complex(x, y, fractal);
		c = move_fractal(c, fractal);
		z->real = 0;
		z->imag = 0;
	}
	else
	{
		c = malloc (sizeof(t_complex));
		if (c == NULL)
			return (0);
		z = from_mlx_to_complex(x, y, fractal);
		z = move_fractal(z, fractal);
		c->real = -0.8;
		c->imag = 0.156;
	}
	iterations = check_stability(z, c);
	free(z);
	free(c);
	return iterations;
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
