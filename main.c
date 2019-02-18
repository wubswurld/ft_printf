/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:24:52 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/31 21:25:33 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	char c = 'a';
	int x = -100;
	int a = 1007;
	char *str;
	str = "babs";
	printf("------CHAR-------\n\n");
	printf("real -2 width: [%-2c]\n", c);
	printf("real -c: [%-c]\n", c);
	printf("real 2 width: [%2c]\n", c);
	ft_printf("mine: [%2c]\n", c);
	ft_printf("mine neg 2 width: [%-2c]\n", c);
	ft_printf("my neg char, no width: [%-c]\n", c);
	ft_printf("my normal char: [%c]\n\n", c);
	
	printf("-----INT----\n\n");
	ft_printf("mine: [%d]\n", -7);
	printf("real: [%d]\n", -7);
	printf("real: [%d]\n", a);
	ft_printf("mine: [%d]\n", a);
	printf("real: [%d]\n", x);
	ft_printf("mine: [%d]\n", x);
	printf("real: [%5d]\n", 0);
	ft_printf("mine: [%5d]\n", 0);
	printf("real: [%5d]\n", -42);
	ft_printf("mine: [%5d]\n", -42);
	printf("real: [%-5d]\n", -42);
	ft_printf("mine: [%-5d]\n", -42);
	printf("real: [%05d]\n", 0);
	ft_printf("mine: [%05d]\n", 0);
	printf("real: [%-5d]\n", 10);
	ft_printf("mine: [%-5d]\n", 10);
	printf("real: [%+5d]\n", 10);
	ft_printf("mine: [%+5d]\n", 10);
	ft_printf("mine: [%d]\n", 1);
	printf("real: [%d]\n", 1);
	ft_printf("mine: the [%d]\n", 1);
	printf("real: the [%d]\n", 1);
	ft_printf("mine: [%d is one]\n", 1);
	printf("real: [%d is one]\n", 1);
	ft_printf("mine: [%d is negative one]\n", -1);
	printf("real: [%d is negative one]\n", -1);
	printf("real: [%d]\n", 4242);
	ft_printf("mine: [%d]\n", 4242);
	printf("real: [%d]\n", -4242);
	ft_printf("mine: [%d]\n", -4242);
	printf("real: [%d]\n", 2147483647);
	ft_printf("mine: [%d]\n", 2147483647);
	printf("real: [%ld]\n", -2147483649);
	ft_printf("mine: [%d]\n\n", -2147483649);
	
	
	printf("-----STRINGS----\n\n");
	ft_printf("mine: [%70s]\n", str);
	printf("real: [%70s]\n", str);
	ft_printf("my str twice: [%s, %s]\n", str, str);
	printf("real: [%-5s]\n", str);
	ft_printf("mine: [%-5s]\n", str);
	ft_printf("mine: [%5s]\n", str);
	printf("real: [%5s]\n\n", str);
	printf("------MORE-STRINGS----\n\n");
	printf("real: [%-5s]\n","");
	ft_printf("mine: [%-5s]\n","");
	printf("real: [%-5s]\n","a");
	ft_printf("mine: [%-5s]\n","a");
	printf("real: [%-5s]\n","ab");
	ft_printf("mine: [%-5s]\n","ab");
	printf("real: [%-5s]\n","abcdefg");
	ft_printf("mine: [%-5s]\n","abcdefg");
	printf("real: [%5s]\n","abcdefg");
	ft_printf("mine: [%5s]\n\n","abcdefg");

	printf("-----PRECISION-----\n\n");
	printf("real: [%.0d]\n", 2);
	printf("real: [%.0f.]\n", 2.2);
	printf("real: [%.1f]\n", 2.2);
	printf("real: [%5.1f]\n", 2.2);
	printf("real: [%.6f]\n", 2.2);
	printf("real: [%5.0d]\n", a);
	printf("real: [%.0d]\n", x);
	printf("real: [%.1d]\n", x);
	printf("real: [%.2d]\n\n", x);

	printf("-----HEX-----\n\n");
	printf("real: [%-20x]\n", 42U);
	ft_printf("mine: [%-20x]\n", 42U);
	printf("real: [%#20x]\n", 42U);
	ft_printf("mine: [%#20x]\n", 42U);
	printf("real: [%#20X]\n", 42U);
	ft_printf("mine: [%#20X]\n", 42U);
	printf("real: [%2X]\n", 42U);
	ft_printf("mine: [%2X]\n", 42U);
	printf("real: [%2x]\n", 42U);
	ft_printf("mine: [%2x]\n", 42U);
	printf("real: [%2x]\n", 542);
	ft_printf("mine: [%2x]\n", 542);
	printf("real: [%5x]\n", 542);
	ft_printf("mine: [%5x]\n", 542);
	printf("real: [%#x]\n", 542);
	ft_printf("mine: [%#x]\n", 542);
	printf("real: [%#X]\n", 542);
	ft_printf("mine: [%#X]\n", 542);
	printf("real: [%5x]\n", -42);
	ft_printf("mine: [%5x]\n", -42);
	printf("real: [%x]\n", -123);
	ft_printf("mine: [%x]\n", -123);
	printf("real: [%5X]\n", -42);
	ft_printf("mine: [%5X]\n\n", -42);
	
	printf("-----OTHER-----\n\n");
	ft_printf("mine: [%%]\n");
	printf("real: [%%]\n");
	ft_printf("mine: [%5%]\n");
	printf("real: [%5%]\n");
	ft_printf("mine: [%%]\n", "test");
	ft_printf("my failing test: [%  %]\n");
	printf("real: [%   %]\n\n");
	printf("----ASTRICT----\n\n");
	printf("real: [%*s]\n", 5, "abc");
	ft_printf("mine: [%*s]\n", 5, "abc");
	printf("real: [%*s]\n", 10, "abc");
	ft_printf("mine: [%*s]\n", 10, "abc");
	printf("real: [%*s]\n", 15, "abc");
	ft_printf("mine: [%*s]\n", 15, "abc");
	return (0);
}
