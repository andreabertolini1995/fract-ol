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
#include <stdio.h>

int main()
{
  double complex imag = 4.0 * I; 
  double real = 3.0; 
  double complex num = real + imag; 
  // print complex number
  printf("z = %.1f%+.1fi\n", creal(num), cimag(num));

  // let's try to square this number
  double complex num_squared;

  num_squared = num * num;
  printf("z = %.1f%+.1fi\n", creal(num_squared), cimag(num_squared));


}