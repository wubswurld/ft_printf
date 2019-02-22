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
	int data = 29;
	char *str;
	str = "babs";
	printf("------CHAR-------\n\n");
	printf("real -2 width: [%-2c]\n", c);
	ft_printf("mine neg 2 width: [%-2c]\n", c);
	printf("real -c: [%-c]\n", c);
	ft_printf("my neg char, no width: [%-c]\n", c);
	printf("real 2 width: [%2c]\n", c);
	ft_printf("mine: [%2c]\n", c);
	printf("real: [%c]\n", c);
	ft_printf("my normal char: [%c]\n", c);
	printf("real: [%50c]\n", c);
	ft_printf("mine: [%50c]\n", c);
	printf("real: [%-50c]\n", c);
	ft_printf("mine: [%-50c]\n\n", c);
	
	printf("-----INT----\n\n");
	printf("real: [% d]\n", 9999);
	ft_printf("mine: [% d]\n", 9999);
	printf("real: [%d]\n", -7);
	ft_printf("mine: [%d]\n", -7);
	printf("real: [%   d]\n", 7);
	ft_printf("mine: [%  d]\n", 7);
	printf("real: [%    d]\n", -7);
	ft_printf("mine: [%   d]\n", -7);
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
	ft_printf("mine: [%10d]\n", 10);
	printf("real: [%10d]\n", 10);
	ft_printf("mine: [%-10d]\n", 10);
	printf("real: [%-10d]\n", 10);
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
	ft_printf("mine: [%d]\n", -2147483649);
	printf("real: [%d]\n", -2035065302);
	ft_printf("mine: [%d]\n\n", -2035065302);
	
	printf("-----INTS USING I-------\n\n");
	printf("real: [%i]\n", -2035065302);
	ft_printf("mine: [%i]\n\n", -2035065302);
	
	
	printf("-----STRINGS----\n\n");
	ft_printf("mine: [%-70s]\n", str);
	printf("real: [%-70s]\n", str);
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
	printf("real: [%-5s]\n","abcd");
	ft_printf("mine: [%-5s]\n","abcd");
	printf("real: [%5s]\n","abcdefg");
	ft_printf("mine: [%5s]\n","abcdefg");
	printf("real: [ Z%s ]\n", "test");
	ft_printf("mine: [ Z%s ]\n\n", "test");
	//printf("real: [%s]\n", NULL);
	//ft_printf("mine: [%s]\n\n", NULL);

	printf("-----PRECISION-----\n\n");
	printf("real: [%.0d]\n", 2);
	printf("real: [%.0f.]\n", 2.2);
	printf("real: [%.1f]\n", 2.2);
	printf("real: [%5.1f]\n", 2.2);
	printf("real: [%.6f]\n", 2.2);
	printf("real: [%5.0d]\n", a);
	printf("real: [%.0d]\n", x);
	printf("real: [%.1d]\n", x);
	printf("real: [%.2d]\n", x);
	printf("real: [%.5s]\n","abcdefg");
	printf("real: [%5.5s]\n","abcdefg");

	printf("-----HEX-----\n\n");
	printf("real: [before %x after]\n", 42);
	ft_printf("mine: [before %x after]\n", 42);
	printf("real: [%-20x]\n", 42U);
	ft_printf("mine: [%-20x]\n", 42U);
	printf("real: [%#20x]\n", 42U);
	ft_printf("mine: [%#20x]\n", 42U);
	printf("real: [%2x]\n", 42U);
	ft_printf("mine: [%2x]\n", 42U);
	printf("real: [%2x]\n", 542);
	ft_printf("mine: [%2x]\n", 542);
	printf("real: [%5x]\n", 542);
	ft_printf("mine: [%5x]\n", 542);
	printf("real: [%#x]\n", 542);
	ft_printf("mine: [%#x]\n", 542);
	printf("real: [%08x]\n", data);
	ft_printf("mine: [%08x]\n", data);
	printf("real: [%5x]\n", -42);
	ft_printf("mine: [%5x]\n", -42);
	printf("real: [%x]\n", -123);
	ft_printf("mine: [%x]\n", -123);
	
	printf("-----BIG-HEX----\n\n");
	printf("real: [before %X after]\n", 42);
	ft_printf("mine: [before %X after]\n", 42);
	printf("real: [%5X]\n", -42);
	ft_printf("mine: [%5X]\n", -42);
	printf("real: [%#X]\n", 542);
	ft_printf("mine: [%#X]\n", 542);
	printf("real: [%#20X]\n", 42U);
	ft_printf("mine: [%#20X]\n", 42U);
	printf("real: [%-30X]\n", -2);
	ft_printf("mine: [%-30X]\n", -2);
	printf("real: [%2X]\n", 42U);
	ft_printf("mine: [%2X]\n", 42U);
	ft_printf("mine: [%x%X%x%X]\n\n", -42, 42, -42, 42);

	printf("-----OCTAL-----\n\n");
	printf("real: [%o]\n", 42);
	ft_printf("mine: [%o]\n", 42);
	printf("real: [%#o]\n", -42);
	ft_printf("mine: [%#o]\n", -42);
	printf("real: [%5o]\n", 42);
	ft_printf("mine: [%5o]\n", 42);
	printf("real: [%10o]\n", 42);
	ft_printf("mine: [%10o]\n", 42);
	printf("real: [%15o]\n", 42);
	ft_printf("mine: [%15o]\n", 42);
	printf("real: [%-5o]\n", 42);
	ft_printf("mine: [%-5o]\n", 42);
	printf("real: [%-10o]\n", 42);
	ft_printf("mine: [%-10o]\n", 42);
	printf("real: [%-15o]\n", 42);
	ft_printf("mine: [%-15o]\n", 42);
	printf("real: [%#5o]\n", 222);
	ft_printf("mine: [%#5o]\n", 222);
	printf("real: [%#10o]\n", 42);
	ft_printf("mine: [%#10o]\n", 42);
	printf("real: [%#15o]\n", 42);
	ft_printf("mine: [%#15o]\n", 42);
	printf("real: [%o]\n", 10);
	ft_printf("mine: [%o]\n\n", 10);
	
	printf("-----OTHER-----\n\n");
	ft_printf("mine: [%-5%]\n");
	printf("real: [%-5%]\n");
	ft_printf("mine: [%5%]\n");
	printf("real: [%5%]\n");
	ft_printf("mine: [%%]\n");
	printf("real: [%%]\n");
	ft_printf("mine: [%  %]\n");
	printf("real: [%   %]\n\n");

	printf("-------UNSIGNED-----\n\n");
	printf("real: [%u]\n", 15);
	printf("real: [%u]\n", 10);
	ft_printf("mine: [%u]\n", 10);
	printf("real: [%u]\n", 5);
	printf("real: [%u]\n", -5);
	printf("real: [%u]\n", -10);
	printf("real: [%10u]\n", 10);
	printf("real: [%-10u]\n\n", 10);
	
	printf("----ASTRICT----\n\n");
	printf("real: [%*s]\n", 5, "abc");
	ft_printf("mine: [%*s]\n", 5, "abc");
	printf("real: [%*s]\n", 10, "abc");
	ft_printf("mine: [%*s]\n", 10, "abc");
	printf("real: [%*s]\n", 15, "abc");
	ft_printf("mine: [%*s]\n", 15, "abc");
	printf("real: [%*s]\n", -5, "abc");
	ft_printf("mine: [%*s]\n", -5, "abc");
	printf("real: [%*s]\n", -10, "abc");
	ft_printf("mine: [%*s]\n", -10, "abc");
	printf("real: [%*s]\n", -15, "abc");
	ft_printf("mine: [%*s]\n", -15, "abc");
	printf("real: [%-*s]\n", 6, "abc");
	ft_printf("mine: [%-*s]\n", 6, "abc");
	// int nb1 = ft_printf("%s", NULL);
	// int nb2 = printf("%s", NULL);
	// // int nb3 = ft_printf("%c", 0);
	// // int nb4 = printf("%c", 0);
	// // int nb5 = ft_printf("%-65x", 42);
	// // int nb6 = printf("%-65x", 42);
	// printf("YOURS %d\n", nb1);
	// printf("OFFICIAL %d\n", nb2);
	// // printf("------------------------------\n");
	// // printf("YOURS %d\n", nb3);
	// // printf("OFFICIAL %d\n", nb4);
	// // printf("------------------------------\n");
	// // printf("YOURS %d\n", nb5);
	// // printf("OFFICIAL %d\n", nb6);
	// // printf("------------------------------\n");
	return (0);
}
