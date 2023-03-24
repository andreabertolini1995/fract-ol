#include "fract_ol.h"

#define BPP sizeof(int32_t)

static mlx_image_t* image;

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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

int32_t main(void)
{
	mlx_t* mlx;

	// Set up the window
    mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	if (!mlx)
		ft_error();

	image = mlx_new_image(mlx, 128, 128);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		ft_error();
	
	// Colour the image white
    memset(image->pixels, 255, image->width * image->height * BPP);
	
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}