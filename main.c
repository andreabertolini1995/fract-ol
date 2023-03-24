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

static mlx_image_t *image;

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Print the window width and height.
// static void ft_print_width_and_height(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

void ft_hook(void *param)
{
	mlx_t *mlx;

	mlx = param;
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

int main(void)
{
	mlx_t *mlx;

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true); // not sure what this line is doing

	// Set up the window - it always opens a 1920x995 window no matter the input patameters though
	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!mlx)
		ft_error();

	// Create an image as big as the window
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		ft_error();

	// Colour the image white (by setting every pixel white)
	// The third parameter tells us how much of the image we color I think
	// Colour one pixel white (the smallest bit of the image I can color)
	// In this way we are going from white to black because those are the colors
	// where R, G, B are always the same
	//ft_memset(image->pixels, 16121855, sizeof(int32_t) * image->height * image->width);
	ft_memset(image->pixels, 16711935, sizeof(int32_t) * image->height * image->width);


	// Draw the image at coordinate (0, 0).
	mlx_image_to_window(mlx, image, 0, 1);

	// Apply hook to move image with the keyboard
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/*
Next steps:
- Color the image a different color than white (generally understand how to access different colors)
- Color multiple individual pixels with different colors --> have multiple colors in the same window
- Understand how to color based on the manderlbrot set:
	- Associate somehow a complex number to every pixel of the window
	- Parse the window pixel by pixel, check the stability of the function with c as its complex number
		associatd and color the pixel accordingly
*/