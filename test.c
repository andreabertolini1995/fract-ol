// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fract_ol.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/* Things to understand about this function / this logic:
	- how often is it called --> documentation says that hooks get executed every frame 
	- if the value of a is very small, transparency is high and thi will result in a not visible color
	- param is set as mlx (i.e., the window) --> probably need to create a customized generic hook where the function takes
		another argment of type void* that is the image, since I can not use global variables
*/
void ft_red_square(void *param)
{
	uint32_t		x;
	uint32_t		y;
	uint32_t		color;
	
	param = NULL;
	x = 0;
	// Colour the left half of the square
	while (x < (image->width)/2)
	{
		y = 0;
		while (y < image->height)
		{
			color = ft_pixel(255, 0, 0, 58);
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
	// Colour the right half of the square
	while (x < (image->width))
	{
		y = 0;
		while (y < image->height)
		{
			color = ft_pixel(0, 255, 0, 58);
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
}

void ft_randomize(void* param)
{
    param = NULL;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			// By doing "% number", the result can never be higher than number by definition of Modulo
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

/* Pretty slow keyboards reaction */
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main()
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop_hook(mlx, ft_red_square, mlx);

	// ft_printf("Random number: %d\n", rand());
	// ft_printf("Modulo with 255: %d\n", rand() % 0xFF);
	// ft_pixel(rand() % 0xFF, rand() % 0xFF, rand() % 0xFF, rand() % 0xFF);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
