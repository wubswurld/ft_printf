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
    if (sp->ptr->tmp > 0)
    {
      if (sp->ptr->tmp == 'c')
      {
          ft_putchar(va_arg(sp->arg, int));
          sp->rtn += 1;
      }
      if (sp->ptr->tmp == 's')
      {
          check_str(sp);
      }
      if (sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i')
      {
          check_digit(sp);
      }
      sp->x++;
    }
    return (sp->rtn);
}

int         check_digit(t_whole *sp)
{
    int     arr;

    arr = va_arg(sp->arg, int);
    if (arr)
        ft_putnbr(arr);
    sp->rtn += num_len(arr);
    return (sp->rtn);
}

int         check_str(t_whole *sp)
{
    int    x;
    char *tp;

    x = 0;
    tp = va_arg(sp->arg, char *);
    ft_putstr(&tp[x]);
    x++;
    sp->rtn += x;
    return (sp->rtn);
}

// int         get_width(const char *format, t_whole *sp)
// {
//     if ()

//     return (sp->rtn);
// }

int         ft_flags(const char *format, t_whole *sp)
{
    while (!mod_strchr(format[sp->x], "sSpdDioOUxXcC") && format[sp->x] != '\0')
    {
        if (format[sp->x + 1] == '-' && format[sp->x + 1] != '\0')
        {
            write (1, "w\n", 2);
        }
        if (format[sp->x + 1] == '+' && format[sp->x] != '\0')
        {
            ft_putchar('+');
        }
        if (format[sp->x] >= '0' && format[sp->x] <= '9' && format[sp->x + 1] != '\0')
        {
            sp->ptr->width = format[sp->x];
            sp->x++;
            //get_width(format, sp);
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
    while (format[sp->x] != '\0')
    {
        if (format[sp->x] != '%')
        {
            ft_putchar(format[sp->x]);
            sp->rtn++;
        }
        if (format[sp->x] == '%')
        {
            if (format[sp->x] != '\0' && format[sp->x + 1] == 'n')
                ft_putchar('\n');
            if (format[sp->x] != '\0' && format[sp->x + 1] == '%')
                ft_putchar('%');
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
    free(sp);
    va_end(sp->arg);
    return(sp->rtn);
}