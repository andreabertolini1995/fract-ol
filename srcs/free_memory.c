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

void	free_point(t_point *point)
{
	free(point->pos);
	free(point);
}

void	free_cursor(t_cursor *cursor)
{
	free_point(cursor->before_zoom);
	free_point(cursor->after_zoom);
	free(cursor);
}

void	free_set(t_set *set)
{
	free(set->origin);
	free(set);
}

void	free_all(t_fractal *fractal)
{
	free_cursor(fractal->cursor);
	free(fractal->zoom);
	free_set(fractal->set);
	free(fractal);
}
