/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:18:22 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/19 17:18:23 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	number_powered;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = 1;
		number_powered = nb;
		while (i < power)
		{
			number_powered = number_powered * nb;
			i++;
		}
		return (number_powered);
	}
}

int	*ft_dec_to_binary(int n, int binary_size)
{
	int	i;
	int	*binary;

	binary = (int *) malloc (sizeof(int) * binary_size);
	if (binary == NULL)
		return (NULL);
	i = binary_size - 1;
	while (i >= 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i--;
	}
	return (binary);
}

void	ft_invert_binary(int *binary, int binary_size)
{
	int	i;

	i = 0;
	while (i < binary_size)
	{
		if (binary[i] == 0)
			binary[i] = 1;
		else
			binary[i] = 0;
		i++;
	}
}

int	*ft_add_one_binary(int *binary, int binary_size)
{
	int	i;

	i = binary_size - 1;
	while (i >= 0)
	{
		if (binary[i] == 1)
			binary[i] = 0;
		else if (binary[i] == 0)
		{
			binary[i] = 1;
			return (binary);
		}
		i--;
	}
	return (binary);
}
