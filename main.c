// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fract_ol.h"

static void ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
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
	return (fractal);
}

void color_fractal(void *param)
{
	uint32_t		x;
	uint32_t		y;
	uint32_t		color;
	t_fractal*		fractal;

	fractal = (t_fractal*) param;
	x = 0;
	while (x < fractal->image->width)
	{
		y = 0;
		while (y < fractal->image->height)
		{
			color = color_set(x, y, fractal->set, fractal->zoom);
			mlx_put_pixel(fractal->image, x, y, color);
			y++;
		}
		x++;
	}
}

void my_zoomhook(double xdelta, double ydelta, void* param)
{
	t_fractal*		fractal;

	fractal = (t_fractal*) param;
    fractal->zoom = fractal->zoom + ydelta;
	if (xdelta < 0)
		puts("Left!");
	else if (xdelta > 0)
		puts("Right!");
}

void my_cursorhook(double xpos, double ypos, void* param)
{
	param = NULL;
	printf("Xpos: %f\n", xpos);
	printf("Ypos:  %f\n", ypos);
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
		mlx_cursor_hook(fractal->window, &my_cursorhook, NULL);
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
	- if I zoom to much (probably in the black) the image rotates
	- the zoom doesn't follow the mouse at the moment
*/
