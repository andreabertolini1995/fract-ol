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

int	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int		i;
	char	**strs;

	i = 0;
	if (!is_char_in_str(str, '.'))
		return (is_int(str));
	else
	{
		strs = ft_split(str, '.');
		if (is_int(strs[0]) && is_int(strs[1]))
			return (1);
	}
	return (0);
}

static void	set_hooks_and_loops(t_fractal *fractal)
{
	color_fractal(fractal);
	mlx_scroll_hook(fractal->window, &zoom_hook, fractal);
	mlx_resize_hook(fractal->window, NULL, NULL);
	mlx_loop(fractal->window);
	mlx_terminate(fractal->window);
	free(fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || (strncmp(argv[1], "mandelbrot", strlen(argv[1]))
			&& strncmp(argv[1], "julia", strlen(argv[1]))))
	{
		printf("Please enter a valid set name.\n");
		printf("Available set names are 'mandelbrot' and 'julia'.\n");
		exit(EXIT_FAILURE);
	}
	else if (!strncmp(argv[1], "julia", strlen(argv[1])))
	{
		if (argc < 4 || !is_number(argv[2]) || !is_number(argv[3]))
		{
			printf("Please enter the complex coordinates of the julia set origin.\n");
			printf("Example: 0.285 0.01.\n");
			exit(EXIT_FAILURE);
		}
		else
			fractal = initialize_fractal(argv[1],
					ft_atof(argv[2]), ft_atof(argv[3]));
	}
	else
		fractal = initialize_fractal(argv[1], 0, 0);
	set_hooks_and_loops(fractal);
	return (EXIT_SUCCESS);
}
