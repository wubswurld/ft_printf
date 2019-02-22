/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:00:39 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/20 10:00:56 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_octal(t_whole *sp)
{
   sp->post = va_arg(sp->arg, int);
    if (sp->ptr->tmp == 'o' && sp->ptr->minus == FALSE)
    {
        sp->output = ft_uitoa_base(sp->post, 8);
        oct_width(sp);
        if (sp->ptr->hash == TRUE)
            write(1, "0", 2);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'o' && sp->ptr->minus == TRUE)
    {
        sp->output = ft_uitoa_base(sp->post, 8);
        if (sp->ptr->hash == TRUE)
            write(1, "0", 2);
        ft_putstr(sp->output);
        oct_width(sp);
    }
}

void        oct_width(t_whole *sp)
{
    int a;

    a = ft_strlen(sp->output);
    if (sp->ptr->hash == TRUE)
        sp->ptr->width = sp->ptr->width - 1;
    while (sp->ptr->width > a)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}