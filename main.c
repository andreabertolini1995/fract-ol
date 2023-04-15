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

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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
				printf("Please enter a valid set name.\n");
				return (EXIT_FAILURE);
			}
		else
		{
			fractal = initialize_fractal(argv[1]);
			mlx_loop_hook(fractal->window, color_fractal, fractal);  // generic hook
			mlx_loop_hook(fractal->window, ft_keys_hook, fractal);   // also a generic hook - why is it not working?
			mlx_scroll_hook(fractal->window, &my_zoomhook, fractal); // specialized hook 
			// mlx_key_hook(fractal->window, &my_keyhook, fractal);
			mlx_resize_hook(fractal->window, NULL, NULL);           // specialized hook 
			mlx_loop(fractal->window);
			mlx_terminate(fractal->window);
			free(fractal); // I don't know if I am freeing also compl and cursor by doing this
			return (EXIT_SUCCESS);
		}
	}
}
