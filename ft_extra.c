/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:57:27 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/31 19:57:29 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putstr(char *str)
{
    int x;

    x = 0;
    while (str[x])
    {
        ft_putchar(str[x]);
        x++;
    }
}

int     ft_strlen(char *str)
{
    int x;

    x = 0;
    while (str[x])
        return (x++);
    return (x);
}

int     num_len(int c)
{
    int x;

    x = 0;
    while (c)
    {
        c /= 10;
        x++;
    }
    return (x);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int	    mod_strchr(char c, char *s1)
{
    int     a;

    a = 0;
    while (s1[a])
    {
        if (s1[a] == c)
            return (1);
        a++;
    }
    return (0);
}

int     ft_atoi()
{
    
}
