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

static void	set_hooks_and_loops(t_fractal *fractal)
{
	color_fractal(fractal);
	mlx_scroll_hook(fractal->window, &zoom_hook, fractal);
	mlx_loop_hook(fractal->window, keys_hook, fractal);
	mlx_resize_hook(fractal->window, NULL, NULL);
	mlx_loop(fractal->window);
	mlx_terminate(fractal->window);
	free_all(fractal);
}

static t_fractal	*initialize_fractal(char *set_type, double x, double y)
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
	fractal->zoom = initialize_zoom(1, 0, START);
	fractal->set = initialize_set(set_type, x, y);
	return (fractal);
}

static void	error_messages(int n)
{
	if (n == 1)
	{
		ft_printf("Please enter a valid set name.\n");
		ft_printf("Available set names are 'mandelbrot' and 'julia'.\n");
	}
	else if (n == 2)
	{
		ft_printf("Please enter the complex coords of the julia set origin.\n");
		ft_printf("Example: 0.285 0.01.\n");
	}
	else
		ft_printf("No need to enter the complex coordinates for mandlebrot.\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot"))
			&& ft_strncmp(argv[1], "julia", ft_strlen("julia"))))
		error_messages(1);
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
	{
		if (argc < 4 || argc >= 5 || !is_number(argv[2]) || !is_number(argv[3]))
			error_messages(2);
		else
		{
			fractal = initialize_fractal(argv[1],
					ft_atof(argv[2]), ft_atof(argv[3]));
			set_hooks_and_loops(fractal);
		}
	}
	else
	{
		if (argc > 2)
			error_messages(3);
		else
			set_hooks_and_loops(initialize_fractal(argv[1], 0, 0));
	}
	return (EXIT_SUCCESS);
}
