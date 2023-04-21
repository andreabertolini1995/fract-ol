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

t_complex	*initialize_complex(double real, double imag)
{
	t_complex	*compl;

	compl = malloc (sizeof(t_complex));
	if (compl == NULL)
		return (NULL);
	compl->real = real;
	compl->imag = imag;
	return (compl);
}

t_point	*initialize_point(double real, double imag)
{
	t_point		*point;

	point = malloc (sizeof(t_point));
	if (point == NULL)
		point = NULL;
	point->pos = initialize_complex(real, imag);
	return (point);
}

t_cursor	*initialize_cursor(void)
{
	t_cursor		*cursor;

	cursor = malloc (sizeof(t_cursor));
	if (cursor == NULL)
		cursor = NULL;
	cursor->before_zoom = initialize_point(0, 0);
	cursor->after_zoom = initialize_point(0, 0);
	return (cursor);
}

t_set	*initialize_set(char *set_type, double x, double y)
{
	t_set	*set;

	set = malloc (sizeof(t_set));
	if (set == NULL)
		set = NULL;
	set->type = set_type;
	set->origin = initialize_complex(x, y);
	return (set);
}

t_zoom	*initialize_zoom(double value, double shift, bool type)
{
	t_zoom		*zoom;

	zoom = malloc (sizeof(t_zoom));
	if (zoom == NULL)
		zoom = NULL;
	zoom->value = value;
	zoom->shift = shift;
	zoom->type = type;
	return (zoom);
}
