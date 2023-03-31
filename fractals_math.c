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

float complex  from_mlx_to_complex(double x, double y)
{
	double			real;
	double complex	imag;
	double complex	num;

	/* The zoom hook can be introduced to change
		the '2' in the equation below */
	real = -1 + 2 *(x / WIDTH);
	imag = (1 - 2 * (y / HEIGHT)) * I;
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

uint32_t	color_stability(double x, double y)
{
	int 		iter;
	uint32_t	color;

	iter = check_stability(x, y);
	if (iter < 60)
		color = ft_pixel(0, iter*4, 255, 58); // blue and its variants
	else if (iter >= 60 && iter < 100)
		color = ft_pixel(255, iter*4, 0, 58); // red and its variants
	else
		color = ft_pixel(0, 0, 0, 58); // black
	return (color);
}

int	check_stability(double x, double y)
{
	int 			i;	
	double complex	num;
	double complex	c;

	c = from_mlx_to_complex(x, y);
	num = 0;
	i = 0;
	while (i < ITERATIONS)
	{
		num = num * num + c;
		if (creal(num) == INFINITY || cimag(num) == INFINITY)
			return i;
		i++;
	}
	return i;
}
