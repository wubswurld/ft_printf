/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:06:12 by jawatter          #+#    #+#             */
/*   Updated: 2019/03/01 12:06:25 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        set_hexlen(t_whole *sp)
{
    if (sp->ptr->len == 1 || sp->ptr->precision == 2 || sp->ptr->precision == 3 || sp->ptr->precision == 4 || sp->ptr->precision == 5)
        sp->p1 = (unsigned long)sp->post; 
    else if (sp->ptr->len == 1)
    {
        printf("lok");
		sp->p1 = (unsigned short)sp->post;
    }
    else if (sp->ptr->len == 0)
		sp->p1 = (unsigned int)sp->post;
    if (sp->ptr->tmp == 'x')
        sp->output = ft_uitoa_base(sp->p1, 16);
}

void        hex_lenmod(t_whole *sp)
{
    // sp->output = ft_uitoa_base(sp->post, 16);
    // sp->cur = ft_strlen(sp->output);
    // printf("%d", sp->ptr->len);
    if (sp->ptr->len == 1 || sp->ptr->precision == 2 || sp->ptr->precision == 3 || sp->ptr->precision == 4 || sp->ptr->precision == 5)
    {
        printf("ok");
        sp->output = ft_uitoa_base(sp->post, 16);
    }
    if (sp->ptr->len == 1)
    {
        printf("okk");
        sp->output = ft_uitoa_base((unsigned short)sp->post, 16);
    }
    if (sp->ptr->len == 2)
        sp->output = ft_uitoa_base((unsigned char)sp->post, 16);
    if (sp->ptr->len == 3)
        sp->output = ft_ultoa_base((unsigned long)sp->post, 16);
    if (sp->ptr->len == 4)
        sp->output = ft_uitoa_base(sp->post, 16);
}

void        ft_len(const char *format, t_whole *sp)
{
    if (format[sp->x + 1] == 'h' && format[sp->x + 2] != 'h')  
        sp->ptr->len = 1;
    else if (format[sp->x + 1] == 'h' && format[sp->x + 2] == 'h')
    { 
        sp->x++;
        sp->ptr->len = 2;
    }
    else if (format[sp->x + 1] == 'l' && format[sp->x + 2] != 'l')
        sp->ptr->len = 3;
    else if (format[sp->x + 1] == 'l' && format[sp->x + 2] == 'l')
    {
        sp->x++;
        sp->ptr->len = 4;
    }
    else if (format[sp->x + 1] == 'L' && format[sp->x + 1] != '\0')
        sp->ptr->len = 5;
    else
        sp->ptr->len = 0;
    sp->x++;
}