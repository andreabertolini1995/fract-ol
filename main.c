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

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

t_complex *initialize_complex(double real, double imag)
{
	t_complex	*compl;

	compl = malloc (sizeof(t_complex));
		if (compl == NULL)
			return (NULL);
	compl->real = real;
	compl->imag = imag;
	return (compl);
}

t_point	*initialize_cursor()
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

t_point	*initialize_center()
{
	t_point		*center;

	center = malloc (sizeof(t_point));
	if (center == NULL)
		return (NULL);
	center->pos = initialize_complex(0, 0);
	center->x = from_real_to_mlx(center->pos->real);
	center->y = from_imag_to_mlx(center->pos->imag);
	return (center);
}

t_fractal *initialize_fractal(char *set)
{
	t_fractal 		*fractal;

	fractal = malloc (sizeof(t_fractal));
	if (fractal == NULL)
		return (NULL);
	fractal->window = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->window)
		ft_error();
	fractal->image = mlx_new_image(fractal->window, WIDTH, HEIGHT);
	if (!fractal->image || (mlx_image_to_window(fractal->window, fractal->image, 0, 0) < 0))
		ft_error();
	fractal->set = set;
	fractal->zoom = 1;
	fractal->cursor = initialize_cursor();
	fractal->center = initialize_center();
	return (fractal);
}

void color_fractal(void *param)
{
	int				x;
	int				y;
	uint32_t		color;
	t_fractal		*fractal;

	fractal = (t_fractal*) param;
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

void my_zoomhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal*) param;
	mlx_get_mouse_pos(fractal->window, &(fractal->cursor->x), &(fractal->cursor->y));
	fractal->cursor->pos = from_mlx_to_complex(fractal->cursor->x, fractal->cursor->y, fractal);
	// printf("Mouse pos: %f + %fi\n", fractal->cursor->pos->real, fractal->cursor->pos->imag);
	if (ydelta < 0)
	{
		fractal->zoom = fractal->zoom * fabs(ydelta * 10);
		printf("Zoom: %f\n", fractal->zoom);
	}
	else if (ydelta > 0)
	{
		fractal->zoom = fractal->zoom / fabs(ydelta * 10);
		printf("Zoom: %f\n", fractal->zoom);
	}
	if (xdelta < 0)
		puts("Left!");
	else if (xdelta > 0)
		puts("Right!");
}

int main(int argc, char **argv)
{
	t_fractal 		*fractal;

	if (argc < 2)
		printf("No set has been specified.\n");
	else
	{
		fractal = initialize_fractal(argv[1]);
		mlx_loop_hook(fractal->window, color_fractal, fractal);
		mlx_scroll_hook(fractal->window, &my_zoomhook, fractal);
		mlx_resize_hook(fractal->window, NULL, NULL);
		mlx_loop(fractal->window);
		mlx_terminate(fractal->window);
		return (EXIT_SUCCESS);
	}
}

/* 
Next steps:
- apply the zoom
	- double check that if you zoom into the black you won't find anything --> how is supposed to be the mandatory part then
	- would be interesting, as an intermediate step, to set the "center" from which it zoomes
	- the zoom doesn't follow the mouse at the moment
*/
