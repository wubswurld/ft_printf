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

void         check_digit(t_whole *sp)
{
    sp->arr = va_arg(sp->arg, int);
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == FALSE)
    {
        int_width(sp);
        if (sp->ptr->plus == TRUE)
            ft_putchar('+');
        ft_putnbr(sp->arr);
    }
      if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == TRUE)
    {
        ft_putnbr(sp->arr);
        int_width(sp);
    }
}

void      check_per(t_whole *sp)
{
    if (sp->ptr->tmp == '%' && sp->ptr->minus == FALSE)
    {
        per_width(sp);    
        ft_putchar('%');
    }
    if (sp->ptr->tmp == '%' && sp->ptr->minus == TRUE)
    {
        ft_putchar('%');
        per_width(sp);
    }
}

void      check_char(t_whole *sp)
{  
    char pst;
    
    pst = va_arg(sp->arg, int);
    sp->output = &pst;
    if (sp->ptr->tmp == 'c' && sp->ptr->minus == FALSE)
    {
        get_width(sp);
        ft_putchar(*sp->output);
    }
    if (sp->ptr->tmp == 'c' && sp->ptr->minus == TRUE)
    {
        ft_putchar(*sp->output);
        get_width(sp);
    }
}
void        check_hex(t_whole *sp)
{
    sp->post = va_arg(sp->arg, int);
    if (sp->ptr->tmp == 'x' && sp->ptr->minus == FALSE)
    {
        sp->output = ft_itoa_base(sp->post, 16);
        hex_width(sp);
        if (sp->ptr->hash == TRUE)
            write(1, "0x", 2);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'x' && sp->ptr->minus == TRUE)
    {
        sp->output = ft_itoa_base(sp->post, 16);
        if (sp->ptr->hash == TRUE)
            write(1, "0x", 2);
        ft_putstr(sp->output);
        hex_width(sp);
    }
}

void         check_str(t_whole *sp)
{
    int    x;
    char *tp;

    x = 0;
    tp = va_arg(sp->arg, char *);
    sp->output = ft_strdup((char *)tp);
    if (sp->ptr->tmp == 's' && sp->ptr->minus == FALSE)
    {
        str_width(sp);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 's' && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        str_width(sp);
    }
}

