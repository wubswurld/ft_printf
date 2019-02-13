/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:42:06 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/06 13:42:20 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         check_digit(t_whole *sp)
{
    int     arr;

    arr = va_arg(sp->arg, int);
    if (arr)
        ft_putnbr(arr);
    if (arr == 0)
        ft_putnbr(0);
    sp->rtn += num_len(arr);
    return (sp->rtn);
}
int        check_char(t_whole *sp)
{  
    char post;
    
    post = va_arg(sp->arg, int);
    sp->output = &post;
    if (sp->ptr->tmp == 'c' && sp->ptr->width == FALSE && sp->ptr->minus == FALSE)
    {
        ft_putchar(*sp->output);
        sp->rtn += 1;
    }
    return (sp->rtn);
}
// void        check_hex(t_whole *sp)
// {
//     if (sp->ptr->tmp == 'x')
//     {
//        ft_itoa_base()
//     }
// }

int         check_str(t_whole *sp)
{
    int    x;
    char *tp;

    x = 0;
    tp = va_arg(sp->arg, char *);
    sp->output = ft_strdup((char *)tp);
    if (sp->ptr->tmp == 's' && sp->ptr->width == FALSE)
    {
        //ft_putstr(sp->output);
        ft_putstr(&tp[x]);
        x++;
    }
    else
    {
        ft_putstr("(null)");
        x++;
    }
    sp->rtn += x;
    return (sp->rtn);
}

// int         check_str(t_whole *sp)
// {
//     if (sp->tp != '\0')
//     {
//         if (sp->ptr->width == FALSE)
//             ft_putstr(&sp->tp[x]);
//         if (sp->ptr->width == TRUE)
//         {
//             get_width(sp);
//             ft_putstr(&sp->tp[x]);
//         }
//     }
//     sp->rtn += x;
//     return (sp->rtn);
// }

// int         check_str(t_whole *sp)
// {
//     if (sp->tp != '\0')
//     {
//         if (sp->ptr->width == FALSE)
//             ft_putstr(&sp->tp[x]);
//         if (sp->ptr->width == TRUE)
//         {
//             get_width(sp);
//             ft_putstr(&sp->tp[x]);
//         }
//     }
//     sp->rtn += x;
//     return (sp->rtn);
// }

