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
    if (sp->ptr->tmp == 'c')
    {
        ft_putchar(va_arg(sp->arg, int));
        sp->rtn += 1;
    }
    if (sp->ptr->tmp == 'C')
    {
        ft_putchar(ft_toupper(va_arg(sp->arg, int)));
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
    printf("%d\n", ft_strlen(tp));
    if (tp != '\0')
    {
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

