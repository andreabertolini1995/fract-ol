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

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
		printf("No set has been specified.\n");
	else
	{
		if (strncmp(argv[1], "mandelbrot", strlen(argv[1]))
			&& strncmp(argv[1], "julia", strlen(argv[1])))
		{
			// Replace this with a list of possible parameters 
			printf("Please enter a valid set name.\n");
			return (EXIT_FAILURE);
		}
		else
		{
			fractal = initialize_fractal(argv[1]);
			color_fractal(fractal);
			mlx_scroll_hook(fractal->window, &zoom_hook, fractal);
			mlx_resize_hook(fractal->window, NULL, NULL);
			mlx_loop(fractal->window);
			mlx_terminate(fractal->window);
			free(fractal);
			return (EXIT_SUCCESS);
		}
	}
}
