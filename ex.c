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

void         check_digit(t_whole *sp)
{
    sp->arr = va_arg(sp->arg, int);
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == FALSE)
    {
        int_width(sp);
        if (sp->ptr->plus == TRUE)
            ft_putchar('+');
        ft_putnbr(sp->arr);
    }
      if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == TRUE)
    {
        ft_putnbr(sp->arr);
        int_width(sp);
    }
}

void      check_per(t_whole *sp)
{
    if (sp->ptr->tmp == '%' && sp->ptr->minus == FALSE)
    {
        per_width(sp);    
        ft_putchar('%');     
    }
    if (sp->ptr->tmp == '%' && sp->ptr->minus == TRUE)
    {
        ft_putchar('%');
        per_width(sp);
    }
}

void      check_char(t_whole *sp)
{  
    char pst;
    
    pst = va_arg(sp->arg, int);
    if (!pst || ft_isdigit(pst))
    {
        ft_putstr("(null)");
        return ;
    }
    sp->output = &pst;
    if (sp->ptr->tmp == 'c' && sp->ptr->minus == FALSE)
    {
        get_width(sp);
        ft_putchar(*sp->output);
    }
    if (sp->ptr->tmp == 'c' && sp->ptr->minus == TRUE)
    {
        ft_putchar(*sp->output);
        get_width(sp);
    }
}
void        check_hex(t_whole *sp)
{
    sp->post = va_arg(sp->arg, int);
    sp->output = ft_uitoa_base(sp->post, 16);
    if (sp->ptr->tmp == 'x' && sp->ptr->minus == FALSE)
    {
        hex_width(sp);
        if (sp->ptr->hash == TRUE)
            write(1, "0x", 2);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'x' && sp->ptr->minus == TRUE)
    {
        if (sp->ptr->hash == TRUE)
            write(1, "0x", 2);
        ft_putstr(sp->output);
        hex_width(sp);
    }
}

void         check_str(t_whole *sp)
{
    char *tp;

    tp = va_arg(sp->arg, char *);
    if (!tp)
    {
        ft_putstr("(null)");
        return ;
    }
    sp->output = ft_strdup((char *)tp);
    if (sp->ptr->tmp == 's' && sp->ptr->minus == FALSE)
    {
        str_width(sp);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 's' && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        str_width(sp);
    }
}

void    check_prec(t_whole *sp)
{
    char *new;

    if (sp->ptr->tmp == 's' && sp->ptr->precision >= 0)
    {
        new = ft_strnew(sp->ptr->precision);
        ft_memccpy(new, sp->output, 0, sp->ptr->precision);
        free(sp->output);
        sp->output = new;
    }
}

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s2)[x] == (unsigned char)c)
		{
			((unsigned char *)s1)[x] = ((unsigned char *)s2)[x];
			return (s1 + x + 1);
		}
		((unsigned char *)s1)[x] = ((unsigned char *)s2)[x];
		x++;
	}
	return (NULL);
}
