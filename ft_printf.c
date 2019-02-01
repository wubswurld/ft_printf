/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:44:56 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/31 19:44:58 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse(const char *format, t_whole *sp)
{
    sp->x = 0;
    sp->rtn = 0;
    while (format[sp->x])
    {
        if (format[sp->x] != '%')
        {
            ft_putchar(format[sp->x]);
            sp->rtn++;
        }
        if (format[sp->x] == '%')
        {
            sp->rtn += ft_flags(format, sp);
            ft_zero(sp);
        }
        if (format[sp->x] == '%' && format[sp->x + 1] == '%')
            ft_putchar('%');
        sp->x++;
    }
    return (sp->rtn);
}
int     ft_printf(const char *format, ...)
{
    t_whole *sp;

    if (!(sp = (t_whole *)malloc(sizeof(t_whole))))
        exit(1);
    va_start(sp->arg, format);
    ft_zero(sp);
    sp->rtn = parse(format, sp);
    va_end(sp->arg);
    return(sp->rtn);
}

