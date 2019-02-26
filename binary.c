/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:33:05 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/24 14:33:23 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_binary(t_whole *sp)
{
    sp->post = va_arg(sp->arg, int);
    sp->output = ft_uitoa_base(sp->post, 2);
    if (sp->ptr->tmp == 'b' && sp->ptr->minus == FALSE)
    {
        binary_width(sp);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'b' && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        binary_width(sp);
    }
}

void    binary_width(t_whole *sp)
{
    int z;

    z = ft_strlen(sp->output);
    while (sp->ptr->width > z)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}
