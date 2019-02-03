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

int         check_flags(t_whole *sp)
{
    while (sp->ptr->tmp > 0)
    {
        char tp;
        tp = va_arg(sp->arg, int);
        va_copy(sp->arg2, sp->arg);
        write(1, "b\n", 2);
        if (sp->ptr->tmp == 'c')
        {
            ft_putchar(va_arg(sp->arg2, int));
        }
    }
    return (0);
}

int         ft_flags(const char *format, t_whole *sp)
{
    while (!(mod_strchr(format[sp->x], "sSpdDioOUxXcC")) && format[sp->x] == '\0')
    {
        break ;
    }
    sp->ptr->tmp = format[sp->x];
    return (check_flags(sp));
}

int			parse(const char *format, t_whole *sp)
{
    sp->x = 0;
    sp->rtn = 0;
    while (format[sp->x] != '\0')
    {
        if (format[sp->x] != '%')
        {
            ft_putchar(format[sp->x]);
            sp->rtn++;
        }
        if (format[sp->x] == '%')
        {
            if (format[sp->x] != '\0' && format[sp->x + 1] == '%')
                ft_putchar('%');
            //add # of chars to the end of rtn & return # of chars
            sp->rtn += ft_flags(format, sp);
            write (1, "l\n", 1);
            ft_zero(sp->ptr);
        }
        sp->x++;
    }
    return (sp->rtn);
}

int     ft_printf(const char *format, ...)
{
    t_whole *sp;

    if (!(sp = (t_whole *)malloc(sizeof(t_whole))))
        exit(1);
    if (!(sp->ptr = (t_adds *)malloc(sizeof(t_adds))))
        exit(1);
    va_start(sp->arg, format);
    ft_zero(sp->ptr);
    sp->rtn = parse(format, sp);
    free(sp);
    va_end(sp->arg);
    return(sp->rtn);
}