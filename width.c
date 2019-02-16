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
    if (format[sp->x] != '\0' && ft_isdigit(format[sp->x + 1]))
    {
        sp->ptr->width += ft_atoi(&format[sp->x + 1]);
        sp->x++;
    }
}

void         get_width(t_whole *sp)
{
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
    while (sp->ptr->width > x)
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
    while (sp->ptr->width > 1)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

void    ft_star(const char *format, t_whole *sp)
{
    int post;

    post = va_arg(sp->arg, int);
    if (format[sp->x + 1] == '*' && format[sp->x + 1] != '\0')
    {
        sp->ptr->width += post;
        sp->x++;
    }
}

