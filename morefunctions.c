/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morefunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:19:52 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/15 21:20:14 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        check_bighex(t_whole *sp)
{
      int post;

    post = va_arg(sp->arg, int);
    if (sp->ptr->tmp == 'X' && sp->ptr->minus == FALSE)
    {
        sp->output = ft_itoa_bigbase(post, 16);
        hex_width(sp);
        if (sp->ptr->hash == TRUE)
            ft_putstr("0X");
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'X' && sp->ptr->minus == TRUE)
    {
        sp->output = ft_itoa_bigbase(post, 16);
        if (sp->ptr->hash == TRUE)
            write(1, "0X", 2);
        ft_putstr(sp->output);
        hex_width(sp);
    }
}

char	*ft_itoa_bigbase(int val, int base)
{
	// max base of 16 is = to 0123456789abcdef
	static char tmp[] = "0123456789ABCDEF";
	static char buf[65];
	char		*ptr;

	ptr = &buf[64];
	*ptr = '\0';
	if (val < 0)
		val = val * -1;
	if (val == 0)
		*--ptr = tmp[val % base];
	while (val != 0)
	{
		*--ptr = tmp[val % base];
		val = val / base;
	}
	if (val < 0)
		*--ptr = '-';
	return (ptr);
}

void    ft_star(const char *format, t_whole *sp)
{
    int post;

    post = va_arg(sp->arg, int);
    if (format[sp->x + 1] == '*' && format[sp->x + 1] != '\0')
    {
        sp->ptr->width += post;
        sp->x++;
    }
}

void     int_width(t_whole *sp)
{
    int x;
    x = num_len(sp->arr);
    if (sp->ptr->plus == TRUE)
        sp->ptr->width -= 1;
    if (sp->ptr->zero)
        sp->ptr->width -= 1;
    if (sp->arr <= 0)
        sp->ptr->width -= 1;
    while (sp->ptr->width > x)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}
