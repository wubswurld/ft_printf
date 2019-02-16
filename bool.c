/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:50:31 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/12 20:50:46 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_minus(const char *format, t_whole *sp)
{
    if (format[sp->x] != '\0' && format[sp->x + 1] == '-')
    {    
        sp->ptr->minus = TRUE;
        sp->x++;
    }
    else
    {
        sp->ptr->minus = FALSE;
        sp->x++;
    }
}

void    ft_plus(const char *format, t_whole *sp)
{
    if (format[sp->x] != '\0' && format[sp->x + 1] == '+')
    {
        sp->ptr->plus = TRUE;
        sp->x++;
    }
    else
    {
        sp->ptr->plus = FALSE;
        sp->x++;
    }
}

void    ft_setzero(const char *format, t_whole *sp)
{
    if (format[sp->x] != '\0' && format[sp->x + 1] == '0')
    {
        sp->ptr->zero = TRUE;
        sp->x++;
    }
    else
    {
        sp->ptr->zero = FALSE;
        sp->x++;
    }
}

void    ft_hash(const char *format, t_whole *sp)
{
    if (format[sp->x] != '\0' && format[sp->x + 1] == '#')
    {
        sp->ptr->hash = TRUE;
        sp->x++;
    }
    else
    {
        sp->ptr->hash = FALSE;
        sp->x++;
    }
}

void    ft_space(const char *format, t_whole *sp)
{
    if (format[sp->x] != '\0' && format[sp->x + 1] == ' ')
    {
        ft_putchar(' ');
        sp->ptr->space = TRUE;
        sp->x++;
    }
    else
    {
        sp->ptr->space = FALSE;
        sp->x++;
    }
}