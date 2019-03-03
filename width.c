/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:30:23 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/13 17:30:33 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_width(const char *format, t_whole *sp)
{
    if (format[sp->x] != '\0' && format[sp->x + 1] >= '1' && format[sp->x + 1] <= '9')
    {
        sp->ptr->width += ft_atoi(&format[sp->x + 1]);
        while (format[sp->x + 1] >= '0' && format[sp->x + 1] <= '9')
            ++sp->x;
    }
}

void         get_width(t_whole *sp)
{
    if (!sp->ptr->width)
        sp->cur = 1;
    else
        sp->cur = sp->ptr->width;
    while (sp->ptr->width > 1)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

void        str_width(t_whole *sp)
{
    int x;

    x = ft_strlen(sp->output);
    while (sp->cur < sp->ptr->width)
        sp->cur += sp->ptr->width - sp->cur;
    if (sp->ptr->minus == TRUE && sp->ptr->zero == TRUE)
        sp->ptr->zero = FALSE;
    while (sp->ptr->width > x)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }

}

void        hex_width(t_whole *sp)
{
    int a;

    a = ft_strlen(sp->output);
    while (sp->cur < sp->ptr->width)
        sp->cur += sp->ptr->width - sp->cur;
    if (sp->ptr->hash == TRUE && !sp->post)
        sp->cur -= 1;
    if (sp->ptr->hash == TRUE)
    {
        sp->ptr->width = sp->ptr->width - 2;
        sp->cur += 2;
    }
    if (sp->ptr->hash && sp->ptr->width)
        sp->cur = sp->cur - 2;
    while (sp->ptr->width > a)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

void    per_width(t_whole *sp)
{
    sp->cur = sp->ptr->width;
    if (!sp->ptr->width)
        sp->cur += 1;
    if (sp->ptr->minus == TRUE && sp->ptr->zero == TRUE)
        sp->ptr->zero = FALSE;
    while (sp->ptr->width > 1)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

