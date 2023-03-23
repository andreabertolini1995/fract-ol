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

#include "ft_printf.h"

static int	ft_binary_to_hex(int *binary, int count,
							char *letter_size, int binary_size)
{
	int	i;
	int	j;
	int	power;
	int	n;

	i = 0;
	j = 0;
	while (i < binary_size)
	{
		n = 0;
		power = 3;
		while (j < i + 4)
		{
			n = n + (binary[j] * ft_iterative_power(2, power));
			j++;
			power--;
		}
		count = count + ft_puthex_count_int(n, letter_size, binary_size);
		i = i + 4;
	}
	free (binary);
	return (count);
}

static int	ft_puthex_strncmp(int n, char *letter_size)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
		count = count + ft_putnbr_count(n);
	else if (!ft_strncmp(letter_size, "lowercase", ft_strlen(letter_size)))
		count = count + ft_putchar_count(n + 87);
	else if (!ft_strncmp(letter_size, "uppercase", ft_strlen(letter_size)))
		count = count + ft_putchar_count(n + 55);
	return (count);
}

int	ft_puthex_count_int(int n, char *letter_size, int binary_size)
{
	int	count;
	int	*binary;

	if (n < 0)
	{
		count = 0;
		binary = ft_dec_to_binary(-n, binary_size);
		ft_invert_binary(binary, binary_size);
		binary = ft_add_one_binary(binary, binary_size);
		count = count + ft_binary_to_hex(binary, count,
				letter_size, binary_size);
	}
	else if (n >= 0 && n < 16)
		count = ft_puthex_strncmp(n, letter_size);
	else
	{
		count = ft_puthex_count_int(n / 16, letter_size, binary_size);
		count = count + ft_puthex_strncmp(n % 16, letter_size);
	}
	return (count);
}
