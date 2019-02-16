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
	printf("------CHAR-------\n");
	printf("real -2 width: [%-2c]\n", c);
	printf("real: [%-c]\n", c);
	printf("real: [%2c]\n", c);
	ft_printf("mine: [%2c]\n", c);
	ft_printf("mine: [%-2c]\n", c);
	ft_printf("my neg char, no width: [%-c]\n", c);
	ft_printf("my normal char: [%c]\n", c);
	
	printf("-----INT----\n\n");
	ft_printf("mine: [%d]\n", -7);
	printf("real: [%d]\n", -7);
	printf("real: [%d]\n", a);
	ft_printf("mine: [%d]\n", a);
	printf("real: [%d]\n", x);
	ft_printf("my int: [%d]\n", x);
	printf("real: [% 05d]\n", 0);
	ft_printf("mine: [%5d]\n", 0);
	
	printf("-----STRINGS----\n\n");
	ft_printf("my string: [%2s]\n", str);
	ft_printf("my str twice: [%s, %s]\n", str, str);
	printf("real: [%-5s]\n", str);
	ft_printf("mine: [%-5s]\n", str);
	ft_printf("mine: [%5s]\n", str);
	printf("real: [%5s]\n", str);
	printf("------MORE-----\n");
	printf("real: [%-5s]\n","");
	ft_printf("[%-5s]\n","");
	printf("real: [%-5s]\n","a");
	ft_printf("[%-5s]\n","a");
	printf("real: [%-5s]\n","ab");
	ft_printf("[%-5s]\n","ab");
	printf("real [%-5s]\n","abcdefg");
	ft_printf("[%-5s]\n","abcdefg");
	printf("real [%5s]\n","abcdefg");
	ft_printf("[%5s]\n","abcdefg");

	printf("-----PRECISION-----\n");
	printf("real: [%.0d]\n", 2);
	printf("real: [%.0f.]\n", 2.2);
	printf("real: [%.1f]\n", 2.2);
	printf("real: [%5.1f]\n", 2.2);
	printf("real: [%.6f]\n", 2.2);

	printf("-----HEX-----\n");
	printf("real: [%2x]\n", 542);
	ft_printf("mine: [%2x]\n", 542);
	printf("real: [%5x]\n", 542);
	ft_printf("mine: [%5x]\n", 542);
	
	printf("-----OTHER-----\n");
	ft_printf("mine: [%%]\n");
	printf("real: [%%]\n");
	ft_printf("mine: [%5%]\n");
	printf("real: [%5%]\n");
	ft_printf("mine: [%%]\n", "test");
	ft_printf("my failing test: [%  %]\n");
	printf("real: [% %]\n");
	ft_printf("mine: [%-9s]\n", "abc");
	ft_printf("mine: [%-9s\t%9s]\n", "abc", "abc");
	printf("real: [%*s]\n", 5, "abc");
	ft_printf("mine: [%*s]\n", 5, "abc");
	printf("real: [%*s]\n", 10, "abc");
	ft_printf("mine: [%*s]\n", 10, "abc");
	printf("real: [%*s]\n", 15, "abc");
	ft_printf("mine: [%*s]\n", 15, "abc");
	return (0);
}
