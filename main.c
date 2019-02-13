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
	char *str;
	str = "babs";
	ft_printf("mine: [%9c]\n", c);
	printf("real: [%-9c]\n", c);
	ft_printf("mine: [%-9c]\n", c);
	ft_printf("mine: [my c: %c]\n", c);
	ft_printf("mine:[%9s]\n", str);
	printf("real:[%9s]", str);
	return (0);
}
