/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:21:28 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/20 13:21:41 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        check_bighex(t_whole *sp)
{
    sp->post = va_arg(sp->arg, int);
     sp->output = ft_uitoa_bigbase(sp->post, 16);
    if (sp->ptr->tmp == 'X' && sp->ptr->minus == FALSE)
    {
        hex_width(sp);
        if (sp->ptr->hash == TRUE)
            ft_putstr("0X");
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'X' && sp->ptr->minus == TRUE)
    {
        if (sp->ptr->hash == TRUE)
            write(1, "0X", 2);
        ft_putstr(sp->output);
        hex_width(sp);
    }
}

void        check_unsigned(t_whole *sp)
{
    sp->ant = va_arg(sp->arg, unsigned int);
    sp->output = ft_ultoa((unsigned int) sp->ant);
    if (sp->ptr->tmp == 'u' && sp->ptr->minus == FALSE)
    {
        u_width(sp);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'u' && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        u_width(sp);
    }
}

void        u_width(t_whole *sp)
{
    int x;
    x = num_len(sp->ant);
    while (sp->ptr->width > x)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

char	*ft_ultoa(unsigned long n)
{
	char			*s;
	unsigned long	nb;
	int				len;

	len = 1;
	nb = n;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (n > 9)
	{
		s[--len] = (n % 10) + 48;
		n /= 10;
	}
	s[--len] = n + 48;
	return (s);
}