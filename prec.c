/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:45:42 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/15 13:45:54 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_prec(const char *format, t_whole *sp)
{
    // if (format[sp->x + 1] == '.' && format[sp->x + 2] == '*')
    // {    
    //     sp->ptr->precision = va_arg(sp->arg, int);
    //     printf("%d", sp->ptr->precision);
    //     sp->x++;
    // }
    if (format[sp->x + 1] == '.' && format[sp->x])
    {
        ++sp->x;
        sp->ptr->precision += ft_atoi(&format[sp->x + 1]);
        while (ft_isdigit(format[sp->x]))
            ++sp->x;
    }
    else
    {
        sp->ptr->precision = FALSE;
        sp->x++;
    }
}

void    check_prec(t_whole *sp)
{
    char *new;

    if (sp->ptr->tmp == 's' && sp->ptr->precision >= 0)
    {
        new = ft_strnew(sp->ptr->precision + 1);
        ft_memcpy(new, sp->output, sp->ptr->precision);
        free(sp->output);
        sp->output = new;
    }
}