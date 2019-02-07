/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:42:06 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/06 13:42:20 by jawatter         ###   ########.fr       */
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

int         check_digit(t_whole *sp)
{
    int     arr;

    arr = va_arg(sp->arg, int);
    if (arr)
        ft_putnbr(arr);
    sp->rtn += num_len(arr);
    return (sp->rtn);
}

int         check_str(t_whole *sp)
{
    int    x;
    char *tp;

    x = 0;
    tp = va_arg(sp->arg, char *);
    if (tp != '\0')
    {
        ft_putstr(&tp[x]);
        x++;
    }
    else
    {
        ft_putstr("(null)");
        x++;
    }
    sp->rtn += x;
    return (sp->rtn);
}
