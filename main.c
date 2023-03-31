// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fract_ol.h"

static mlx_image_t* image;

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void color_fractal(void* param)
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
			color = color_stability(x, y);			
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
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
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/* 
Next steps:
- understand how to avoid the distortion of the image, no matter the size of the window
- apply a hook to be able to expand and reduce the window and re-run the whole colouring again (should be fairly straigthforward)
- center the image when the window opens
- extend the same logic to the Julia set (and understand how to obtain it)
- apply the zoom
*/
