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
#include <stdio.h>

int	ft_first_conditionals(va_list ap, const char *str, int i)
{
	int		count;
	char	*s;

	count = 0;
	if (str[i + 1] == 'c')
		count = count + ft_putchar_count(va_arg(ap, int));
	else if (str[i + 1] == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			count = count + ft_putstr_count("(null)");
		else
			count = count + ft_putstr_count(s);
	}
	else if (str[i + 1] == 'p')
		count = count + ft_putaddr_count(va_arg(ap, void *));
	else if (str[i + 1] == 'd')
		count = count + ft_putnbr_count(va_arg(ap, int));
	else if (str[i + 1] == 'i')
		count = count + ft_putnbr_count(va_arg(ap, int));
	return (count);
}

int	ft_second_conditionals(va_list ap, const char *str, int i)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'u')
		count = count + ft_putunbr_count(va_arg(ap, unsigned int));
	else if (str[i + 1] == 'x')
		count = count + ft_puthex_count_int(va_arg(ap, int), "lowercase", 32);
	else if (str[i + 1] == 'X')
		count = count + ft_puthex_count_int(va_arg(ap, int), "uppercase", 32);
	else if (str[i + 1] == '%')
		count = count + ft_putchar_count('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count = count + ft_first_conditionals(ap, str, i);
			count = count + ft_second_conditionals(ap, str, i);
			i++;
		}
		else
			count = count + ft_putchar_count(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
