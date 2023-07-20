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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);

int		ft_putstr_count(char *s);
int		ft_putchar_count(char c);
int		ft_putnbr_count(int n);
int		ft_putunbr_count(unsigned int n);
int		ft_putaddr_count(void *n);

int		ft_puthex_count_int(int n, char *letter_size, int binary_size);
int		ft_puthex_count_ulong(unsigned long n,
			char *letter_size, int binary_size);

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		*ft_dec_to_binary(int n, int binary_size);
void	ft_invert_binary(int *binary, int binary_size);
int		*ft_add_one_binary(int *binary, int binary_size);
int		ft_iterative_power(int nb, int power);

#endif
