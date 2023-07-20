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
	num->real = (-1 + 2 * (x / WIDTH)) * WIDTH / HEIGHT * fractal->zoom->value;
	num->imag = (1 - 2 * (y / HEIGHT)) * fractal->zoom->value;
	return (num);
}

t_complex	*move_fractal(t_complex *num, t_fractal *fractal)
{
	double	diff_x;
	double	diff_y;

	diff_x = fractal->cursor->after_zoom->pos->real
		- fractal->cursor->before_zoom->pos->real;
	diff_y = fractal->cursor->after_zoom->pos->imag
		- fractal->cursor->before_zoom->pos->imag;
	if (fractal->zoom->type == IN)
	{
		num->real = num->real + (ZOOM_FACTOR * fractal->zoom->shift) * diff_x;
		num->imag = num->imag + (ZOOM_FACTOR * fractal->zoom->shift) * diff_y;
	}
	else if (fractal->zoom->type == OUT)
	{
		num->real = num->real - fractal->zoom->shift * diff_x;
		num->imag = num->imag - fractal->zoom->shift * diff_y;
	}
	return (num);
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
		{
			free(tmp);
			return (i);
		}
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

	if (!ft_strncmp(fractal->set->type, "mandelbrot", ft_strlen("mandelbrot")))
	{
		c = from_mlx_to_complex(x, y, fractal);
		c = move_fractal(c, fractal);
		z = initialize_complex(0, 0);
	}
	else
	{
		z = from_mlx_to_complex(x, y, fractal);
		z = move_fractal(z, fractal);
		c = initialize_complex(fractal->set->origin->real,
				fractal->set->origin->imag);
	}
	iterations = check_stability(z, c);
	free(z);
	free(c);
	return (iterations);
}
