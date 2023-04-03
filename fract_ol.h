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

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <complex.h> // not sure I am allowed to use this one
# include <math.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"

// I don't understand how changing these values makes any difference nor what they represent
# define WIDTH 1920 
# define HEIGHT 995
# define ITERATIONS 100

// Fractals math
float complex   from_mlx_to_complex(double x, double y);
uint32_t        color_set(double x, double y, char *set);
int             create_set(double x, double y, char *set);
int             check_stability(double complex z, double complex c);

// MLX-related functions
int32_t         ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

#endif