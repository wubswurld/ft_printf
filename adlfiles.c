/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adlfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:22:21 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/26 15:24:06 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

char	mod_strchr(char *s1, char c)
{
	int x;

	x = 0;
	while (s1[x])
	{
		if (s1[x] == c)
			return (1);
		x++;
	}
	return (0);
}