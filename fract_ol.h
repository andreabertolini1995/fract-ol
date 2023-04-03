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

// I don't understand how changing these values makes any difference nor what they represent
# define WIDTH 1920 
# define HEIGHT 995
# define ITERATIONS 100

// Complex number sruct
typedef struct s_complex
{
    double  real;
    double  imag; 
}   t_complex;

// Cursor struct
typedef struct s_cursor
{
    int32_t     x;
    int32_t     y;
    t_complex   *pos;
}   t_cursor;

// Fractals struct
typedef struct s_fractal
{
    mlx_t			    *window;
	mlx_image_t         *image;
	double              zoom;
    char                *set;
    t_cursor            *cursor;
}	t_fractal;

// Initialization
t_complex   *initialize_complex();
t_cursor	*initialize_cursor();
t_fractal   *initialize_fractal(char *set);
void        ft_error(void);

// Fractals math
t_complex       *from_mlx_to_complex(double x, double y, t_fractal *fractal);
uint32_t        color_set(double x, double y, t_fractal *fractal);
int             create_set(double x, double y, t_fractal *fractal);
int             check_stability(t_complex *z, t_complex *c);
// t_complex       *center_fractal(double x, double y, t_fractal *fractal);


// MLX-related functions
int32_t         ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// Hooks
void            color_fractal(void *param);
void            my_zoomhook(double xdelta, double ydelta, void* param);
void            my_cursorhook(double xpos, double ypos, void* param);

#endif