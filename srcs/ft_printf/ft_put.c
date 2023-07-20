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

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *s)
{
	int	length;

	length = ft_strlen(s);
	write(1, s, length);
	return (length);
}

int	ft_putnbr_count(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = count + 11;
	}
	else if (n >= 0 && n < 10)
	{
		count = count + ft_putchar_count(n + 48);
	}
	else if (n >= 10)
	{
		count = count + ft_putnbr_count(n / 10);
		count = count + ft_putchar_count((n % 10) + 48);
	}
	else if (n < 0)
	{
		count = count + ft_putchar_count(45);
		count = count + ft_putnbr_count(-n);
	}
	return (count);
}

int	ft_putunbr_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 10)
	{
		count = count + ft_putchar_count(n + 48);
	}
	else if (n >= 10)
	{
		count = count + ft_putunbr_count(n / 10);
		count = count + ft_putchar_count((n % 10) + 48);
	}
	else if (n < 0)
		count = count + ft_putunbr_count(UINT_MAX + n + 1);
	return (count);
}

int	ft_putaddr_count(void *n)
{
	int				count;
	unsigned long	temp;

	temp = (unsigned long) n;
	count = 0;
	count = count + ft_putchar_count('0');
	count = count + ft_putchar_count('x');
	count = count + ft_puthex_count_ulong(temp, "lowercase", 64);
	return (count);
}
