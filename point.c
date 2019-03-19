/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:37:48 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/22 10:38:03 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_point(t_whole *sp)
{
    void    *vp;

    vp = va_arg(sp->arg, void *);
    sp->output = ft_ulltoa_base((unsigned long long)vp, 16);
    sp->cur = ft_strlen(sp->output) + 2;
    if (sp->ptr->tmp == 'p' && sp->ptr->minus == FALSE)
    {
        point_width(sp);
        ft_putstr("0x");
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'p' && sp->ptr->minus == TRUE)
    {
        ft_putstr("0x");
        ft_putstr(sp->output);
        point_width(sp);
    }
}

void    point_width(t_whole *sp)
{
    int z;

    z = ft_strlen(sp->output) + 2;
    while (sp->cur < sp->ptr->width)
        sp->cur += sp->ptr->width - sp->cur;
    while (sp->ptr->width > z)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}
