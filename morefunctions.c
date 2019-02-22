/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morefunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:19:52 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/15 21:20:14 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_star(const char *format, t_whole *sp)
{
    int post;

    post = va_arg(sp->arg, int);
    if (post < 0)
    {
        post *= -1;
        sp->ptr->minus = TRUE;
    }
    if (format[sp->x + 1] == '*' && format[sp->x + 1] != '\0')
    {
        sp->ptr->width += post;
        sp->x++;
    }
}

void     int_width(t_whole *sp)
{
    int x;
    x = num_len(sp->arr);
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