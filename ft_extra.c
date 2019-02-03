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

void    ft_zero(t_adds *ptr)
{
    ptr->plus = 0;
    ptr->minus = 0;
    ptr->width = 0;
    ptr->precision = 0;
    ptr->zero = 0;
    ptr->space = 0;
    ptr->len = 0;
    ptr->hash = 0;
}

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

char	mod_strchr(char c, char *s1)
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
