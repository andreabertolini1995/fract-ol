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

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920 
# define HEIGHT 995
# define ITERATIONS 400
# define ZOOM_FACTOR 0.7
# define IN 0
# define OUT 1
# define START 2
typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_point
{
	int32_t		x;
	int32_t		y;
	t_complex	*pos;
}	t_point;

typedef struct s_cursor
{
	t_point	*before_zoom;
	t_point	*after_zoom;
}	t_cursor;

typedef struct s_zoom
{
	double				value;
	bool				type;
	double				shift;
}	t_zoom;

typedef struct s_fractal
{
	mlx_t				*window;
	mlx_image_t			*image;
	t_cursor			*cursor;
	t_zoom				*zoom;
	char				*set;
	t_complex			*julia;
}	t_fractal;

// Initialization
t_fractal	*initialize_fractal(char *set);
t_complex	*initialize_complex(double real, double imag);
t_point		*initialize_point(double real, double imag);
t_cursor	*initialize_cursor(void);
t_zoom		*initialize_zoom(void);

// Fractals math
t_complex	*from_mlx_to_complex(double x, double y, t_fractal *fractal);
int			create_set(double x, double y, t_fractal *fractal);
int			check_stability(t_complex *z, t_complex *c);
t_complex	*move_fractal(t_complex *num, t_fractal *fractal);

// Hooks
void		zoom_hook(double xdelta, double ydelta, void *param);

// Utils
void		ft_error(void);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		store_cursor_position(t_fractal *fractal, t_point *cursor);
uint32_t	color_set(double x, double y, t_fractal *fractal);
void		color_fractal(t_fractal *fractal);

#endif