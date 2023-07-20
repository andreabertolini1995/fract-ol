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

int	is_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	char	**strs;

	if (!is_char_in_str(str, '.'))
		return (is_int(str));
	else
	{
		strs = ft_split(str, '.');
		if (is_int(strs[0]) && is_int(strs[1]))
			return (1);
	}
	return (0);
}

double	calc_divider(int length)
{
	int	i;
	int	n;

	i = 1;
	n = 10;
	while (i < length)
	{
		n = n * 10;
		i++;
	}
	return (n);
}

double	ft_atof(char *str)
{
	char	**strs;
	int		n;
	int		m;
	double	result;

	if (!is_char_in_str(str, '.'))
		result = ft_atoi(str);
	else
	{
		strs = ft_split(str, '.');
		n = abs(ft_atoi(strs[0]));
		m = atoi(strs[1]);
		result = m / calc_divider(ft_strlen(strs[1])) + n;
		if (str[0] == '-')
			return (-result);
	}
	return (result);
}
