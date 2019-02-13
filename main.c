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
	printf("[%-c\n]", c);
	printf("[real: %d]\n", x);
	ft_printf("[%d]\n", x);
	ft_printf("[%s]\n", str);
	ft_printf("[%s, %s]\n", str, str);
	printf("[real: %-5s]\n", str);
	ft_printf("[this is %s, i am %d years old and my name starts with %c]", str, x, c);
	return (0);
}
