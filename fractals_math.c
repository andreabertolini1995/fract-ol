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

t_complex  *from_mlx_to_complex(double x, double y, t_fractal *fractal)
{
	t_complex *num;

	num = malloc (sizeof(t_complex));
	if (num == NULL)
		return (NULL);
	// Still not clear how to apply the zoom
	num->real = ((-1 + 2 * (x / WIDTH)) * WIDTH/HEIGHT - fractal->cursor->pos->real) * fractal->zoom;
	num->imag = ((1 - 2 * (y / HEIGHT)) - fractal->cursor->pos->imag) * fractal->zoom;
	return num;
}

// t_complex *center_fractal(t_complex *num, t_fractal *fractal)
// {
// 	num->real = num->real + fractal->center->real;
// 	num->imag = num->imag + fractal->center->imag;
// }

// t_complex  *shift_fractal(double x, double y, t_fractal *fractal)
// {
// 	t_complex *num;

// 	num = malloc (sizeof(t_complex));
// 	if (num == NULL)
// 		return (NULL);
// 	num->real = (-1 + 2 * (x / WIDTH) + fractal->cursor->x) * WIDTH/HEIGHT * fractal->zoom;
// 	num->imag = ((1 - 2 * (y / HEIGHT)) + fractal->cursor->y) * fractal->zoom;
// 	return num;
// }

/* Inverse functions of the above function. */
int	from_real_to_mlx(double real)
{
	int	x;

	x = ((real + 1) * WIDTH)/2;
	return (x);
}

int	from_imag_to_mlx(double imag)
{
	int	y;

	y = ((1 - imag) * HEIGHT)/2;
	return (y);
}

int check_stability(t_complex *z, t_complex *c)
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
			return i;
		i++;
	}
	return i;
}

int	create_set(double x, double y, t_fractal *fractal)
{
	t_complex	*z;
	t_complex	*c;

	z = malloc (sizeof(t_complex));
	if (z == NULL)
		return (0);
	c = malloc (sizeof(t_complex));
	if (c == NULL)
		return (0);
	if (!strncmp(fractal->set, "mandelbrot", strlen(fractal->set)))  // to change with my own functions
	{
		c = from_mlx_to_complex(x, y, fractal);
		z->real = 0;
		z->imag = 0;
	}
	else
	{
		z = from_mlx_to_complex(x, y, fractal);
		c->real = -0.8;
		c->imag = 0.156;
	}
	return (check_stability(z, c));
}

uint32_t	color_set(double x, double y, t_fractal *fractal)
{
	int 		iter;
	uint32_t	color;

	iter = create_set(x, y, fractal);
	if (iter < 60)
		color = ft_pixel(0, iter*4, 255, 58); // blue and its variants
	else if (iter >= 60 && iter < 100)
		color = ft_pixel(255, iter*4, 0, 58); // red and its variants
	else
		color = ft_pixel(0, 0, 0, 58); // black
	return (color);
}
