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
	char *str;
	str = "babs";
	printf("[real -2 width: %-2c]\n", c);
	printf("[real: %-c]\n", c);
	ft_printf("[my neg char, no width: %-c]\n", c);
	ft_printf("[my normal char: %c]\n", c);
	printf("[real: %d]\n", x);
	ft_printf("[my int: %d]\n", x);
	ft_printf("[my string: %s]\n", str);
	ft_printf("[my str twice: %s, %s]\n", str, str);
	printf("[real: %s]\n", str);
	ft_printf("[this is %s, i am %d years old and my name starts with %c]\n", str, x, c);
	printf("[%20c]\n", c);
	ft_printf("[%1c]\n", c);
	ft_printf("[%-1c]\n", c);
	return (0);
}
