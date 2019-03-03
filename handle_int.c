/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:30:55 by jawatter          #+#    #+#             */
/*   Updated: 2019/03/01 12:35:50 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void         handle_intmod(t_whole *sp)
{
    long a;

    a = (long long)sp->arr;
    if (!sp->ptr->len)
        sp->output = ft_itoa(sp->arr);
    if (sp->ptr->len == 1)
        sp->output = ft_itoa((short)sp->arr);
    if (sp->ptr->len == 2)
        sp->output = ft_itoa((char)sp->arr);
    if (sp->ptr->len == 3 || sp->ptr->len == 4)
        sp->output = ft_ltoa((long)a);
}

void         check_digit(t_whole *sp)
{
    sp->arr = va_arg(sp->arg, long);
    if (!sp->ptr->len || sp->ptr->len == 1 || sp->ptr->len == 2 || sp->ptr->len == 3 || sp->ptr->len == 4)
        handle_intmod(sp);
    sp->cur = ft_strlen(sp->output);
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == FALSE)
    {
        int_width(sp);
        if (sp->ptr->plus == TRUE && sp->arr >= 0)
            ft_putchar('+');
        ft_putstr(sp->output);
        //ft_putnbr(sp->arr);
    }
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        //ft_putnbr(sp->arr);
        int_width(sp);
    }
}
/*void         check_digit(t_whole *sp)
{
    long a;
    sp->arr = va_arg(sp->arg, long);
    a = (long long)sp->arr;
    if (!sp->ptr->len)
        sp->output = ft_itoa(sp->arr);
    if (sp->ptr->len == 1)
        sp->output = ft_itoa((short)sp->arr);
    if (sp->ptr->len == 2)
        sp->output = ft_itoa((char)sp->arr);
    if (sp->ptr->len == 3 || sp->ptr->len == 4)
        sp->output = ft_ltoa((long)a);
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == FALSE)
    {
        int_width(sp);
        if (sp->ptr->plus == TRUE && sp->arr > 0)
            ft_putchar('+');
        ft_putstr(sp->output);
        //ft_putnbr(sp->arr);
    }
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        //ft_putnbr(sp->arr);
        int_width(sp);
    }
}*/
void     int_width(t_whole *sp)
{
    int x;
    x = num_len(sp->arr);
    while (sp->cur < sp->ptr->width)
        sp->cur += sp->ptr->width - sp->cur;
    if (sp->ptr->plus == TRUE)
        sp->ptr->width -= 1;
    if (sp->arr <= 0)
        sp->ptr->width -= 1;
    if (sp->ptr->space == TRUE && sp->arr >= 0)
        ft_putchar(' ');
    while (sp->ptr->width > x)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

