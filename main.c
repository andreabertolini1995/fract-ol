// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fract_ol.h"

static mlx_image_t* image;
double	zoom_factor = 1;

static void ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void color_fractal(void *param)
{
	uint32_t		x;
	uint32_t		y;
	uint32_t		color;
	
	param = NULL;
	x = 0;
	while (x < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			color = color_set(x, y, "julia");			
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
}

/* This hook will control the zooming in and out of the fractal. */
void my_zoomhook(double xdelta, double ydelta, void* param)
{
	param = NULL;
	zoom_factor = zoom_factor + ydelta;
	if (xdelta < 0)
		puts("Left!");
	else if (xdelta > 0)
		puts("Right!");
}

/* Hook to obtain the position (coordinates x and y) of the cursor. */
void my_cursorhook(double xpos, double ypos, void* param)
{
	param = NULL;
	printf("Xpos: %f\n", xpos);
	printf("Ypos:  %f\n", ypos);
}

int main()
{
	mlx_t* mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!mlx)
		ft_error();
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		ft_error();
	mlx_loop_hook(mlx, color_fractal, mlx);
	mlx_scroll_hook(mlx, &my_zoomhook, NULL);
	mlx_cursor_hook(mlx, &my_cursorhook, NULL);
	mlx_resize_hook(mlx, NULL, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/* 
Next steps:
- apply the zoom
	- double check that if you zoom into the black you won't find anything --> how is supposed to be the mandatory part then
	- if I zoom to much (probably in the black) the image rotates
	- the zoom doesn't follow the mouse at the moment
- organize the code in structs? Maybe the complex number struct?
- understand how to write customized hooks
*/
