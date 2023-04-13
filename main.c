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

t_complex	*initialize_complex(double real, double imag)
{
	t_complex	*compl;

	compl = malloc (sizeof(t_complex));
	if (compl == NULL)
		return (NULL);
	compl->real = real;
	compl->imag = imag;
	return (compl);
}

t_point	*initialize_cursor(void)
{
	t_point		*cursor;

	cursor = malloc (sizeof(t_point));
	if (cursor == NULL)
		return (NULL);
	cursor->x = 0;
	cursor->y = 0;
	cursor->pos = initialize_complex(0, 0);
	return (cursor);
}

t_fractal	*initialize_fractal(char *set)
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
	fractal->set = set;
	fractal->zoom = 1;
	fractal->zoomed = IN;
	fractal->cursor = initialize_cursor();
	return (fractal);
}

void	color_fractal(void *param)
{
	int				x;
	int				y;
	uint32_t		color;
	t_fractal		*fractal;

	fractal = (t_fractal *) param;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color = color_set(x, y, fractal);
			mlx_put_pixel(fractal->image, x, y, color);
			y++;
		}
		x++;
	}
}

// Specialized hook - it works but can't re render - might need to use a generic hook as mentioned in the documentation
// void my_keyhook(mlx_key_data_t keydata, void* param)
// {
// 	t_fractal	*fractal;

// 	fractal = (t_fractal *) param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(fractal->window);
// 	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
// 	{
// 		fractal->image->instances[0].y -= 5;
// 		color_fractal(fractal);
// 	}
// 	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
// 		fractal->image->instances[0].y += 5;
// 	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
// 		fractal->image->instances[0].x -= 5;
// 	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
// 		fractal->image->instances[0].x += 5;
// }

// Somehow this does not work well when called 'together' with the other hook
void	ft_keys_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (mlx_is_key_down(fractal->window, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->window);
	if (mlx_is_key_down(fractal->window, MLX_KEY_UP))
		fractal->image->instances[0].y -= 5;
	if (mlx_is_key_down(fractal->window, MLX_KEY_DOWN))
		fractal->image->instances[0].y += 5;
	if (mlx_is_key_down(fractal->window, MLX_KEY_LEFT))
		fractal->image->instances[0].x -= 5;
	if (mlx_is_key_down(fractal->window, MLX_KEY_RIGHT))
		fractal->image->instances[0].x += 5;
}

void	my_zoomhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	mlx_get_mouse_pos(fractal->window,
		&(fractal->cursor->x), &(fractal->cursor->y));
	fractal->cursor->pos = from_mlx_to_complex(fractal->cursor->x,
			fractal->cursor->y, fractal);
	// printf("Mouse pos: %f + %fi\n", fractal->cursor->pos->real,
	// 	fractal->cursor->pos->imag);
	printf("Zoom: %f\n", fractal->zoom);
	if (ydelta > 0) // zoom in
	{
		fractal->zoom = fractal->zoom / 0.9;
		fractal->zoomed = IN;
	}
	else if (ydelta < 0) // zoom out
	{
		fractal->zoom = fractal->zoom * 0.9;
		fractal->zoomed = OUT;
	}
	if (xdelta < 0)
		printf("Left!");
	else if (xdelta > 0)
		printf("Right!");
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
