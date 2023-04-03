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

extern double zoom_factor;
extern double Xpos;
extern double Ypos;
extern double Xposition;
extern double Yposition;

float complex  from_mlx_to_complex(double x, double y, double zoom)
{
	double			real;
	double complex	imag;
	double complex	num;

	real = (-1 + 2 * (x / WIDTH)) * WIDTH/HEIGHT * zoom;
	imag = ((1 - 2 * (y / HEIGHT)) * I) * zoom;
	num = real + imag;
	return num;
}

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

int check_stability(double complex z, double complex c)
{
	int	i;

	i = 0;
	while (i < ITERATIONS)
	{
		z = z * z + c;
		if (creal(z) == INFINITY || cimag(z) == INFINITY)
			return i;
		i++;
	}
	return i;
}

int	create_set(double x, double y, char *set, double zoom)
{
	double complex	z;
	double complex	c;

	if (!strncmp(set, "mendelbrot", strlen(set)))  // to change with my own functions
	{
		c = from_mlx_to_complex(x, y, zoom);
		z = 0;
	}
	else
	{
		z = from_mlx_to_complex(x, y, zoom);
		c = -0.8 + 0.156 * I;
	}
	return (check_stability(z, c));
}

uint32_t	color_set(double x, double y, char *set, double zoom)
{
	int 		iter;
	uint32_t	color;

	// iter = check_stability_mandelbrot(x, y);
	iter = create_set(x, y, set, zoom);
	if (iter < 60)
		color = ft_pixel(0, iter*4, 255, 58); // blue and its variants
	else if (iter >= 60 && iter < 100)
		color = ft_pixel(255, iter*4, 0, 58); // red and its variants
	else
		color = ft_pixel(0, 0, 0, 58); // black
	return (color);
}
