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

void    ft_zero(t_adds *ptr)
{
    ptr->plus = 0;
    ptr->minus = 0;
    ptr->width = 0;
    ptr->precision = 0;
    ptr->zero = 0;
    ptr->space = 0;
    ptr->len = 0;
    ptr->hash = 0;
}

int        check_flags(t_whole *sp)
{
    if (sp->ptr->tmp)
    {
      if (sp->ptr->tmp == 'c')
          check_char(sp); 
      if (sp->ptr->tmp == 's')
          check_str(sp);
      if (sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i')
          check_digit(sp);
        sp->x++;
    }
    //   if (sp->ptr->tmp == 'x' || sp->ptr->tmp == 'X')
    //       check_hex(sp);
    return (sp->rtn); 
}

int         check_width(t_whole *sp)
{
    sp->a = 0;
    while (sp->a < sp->ptr->width)
    {
       ft_putchar(' ');
       sp->a++;
    }
    sp->rtn += sp->a;
    return (sp->rtn);
}

int         ft_flags(const char *format, t_whole *sp)
{
    if (!mod_strchr(format[sp->x], "sSpdDioOUxXcC") && format[sp->x])
    {
        if (format[sp->x] != '\0' && format[sp->x + 1] == '-')
        {    
            sp->ptr->minus = 1;
            sp->x++;
        }
        if (format[sp->x + 1] == '+' && format[sp->x] != '\0')
            sp->ptr->plus = 1;
        if (format[sp->x + 1] == '0' && format[sp->x + 1] != '\0')
            sp->ptr->zero = 1;
        if (format[sp->x + 1] == '#' && format[sp->x + 1] != '\0')
            sp->ptr->hash = 1;
        if (format[sp->x + 1] == ' ' && format[sp->x + 1] != '\0')
            sp->ptr->space = 1;
        if (format[sp->x + 1] == '.' && format[sp->x + 1] != '\0')
            sp->ptr->precision = 1;    
        if (ft_isdigit(format[sp->x + 1]) && format[sp->x])
        {
            sp->ptr->width = ft_atoi(&format[sp->x + 1]);
            check_width(sp);
            sp->x++;
        }
        sp->rtn++;
    }
    sp->ptr->tmp = format[sp->x + 1];
    return (check_flags(sp));
}

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
            if (format[sp->x + 1] == 'n')
            {
                ft_putchar('\n');
                sp->x++;
            }
            //add # of chars to the end of rtn & return # of chars
            sp->rtn += ft_flags(format, sp);
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
    va_end(sp->arg);
    return(sp->rtn);
}