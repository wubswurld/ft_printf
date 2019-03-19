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
    sp->cur = ft_strlen(sp->output);
    if (sp->ptr->tmp == 'X' && sp->ptr->minus == FALSE)
    {
        hex_width(sp);
        if (sp->ptr->hash == TRUE && sp->post != 0)
        {
            ft_putstr("0X");
            sp->cur += 2;
        }
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'X' && sp->ptr->minus == TRUE)
    {
        if (sp->ptr->hash == TRUE && sp->post != 0)
        {
            write(1, "0X", 2);
            sp->cur += 2;
        }
        ft_putstr(sp->output);
        hex_width(sp);
    }
}

void        unsignedmod(t_whole *sp)
{
    if (sp->ptr->len == 0)
        sp->output = ft_ultoa((unsigned int)sp->ant);
    if (sp->ptr->len == 1)
        sp->output = ft_ultoa((unsigned short)sp->ant);
    if (sp->ptr->len == 2)
        sp->output = ft_ultoa((unsigned char)sp->ant);
    if (sp->ptr->len == 3 || sp->ptr->len == 4)
        sp->output = ft_ultoa((unsigned long)sp->ant);
}

void        check_unsigned(t_whole *sp)
{
    sp->ant = va_arg(sp->arg, unsigned int);
    if (sp->ptr->len == 0|| sp->ptr->len == 1 || sp->ptr->len == 2 || sp->ptr->len == 3 || sp->ptr->len == 4)
        unsignedmod(sp);
    sp->cur = ft_strlen(sp->output);
    // if (sp->ant >= 4294967295)
    //     ft_putstr("4294967296");
    prec_unsigned(sp);
    if (sp->ant >= 4294967295)
    {
        ft_putstr("4294967296");
        return ;
    }
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
    int q1;
    q1 = ft_strlen(sp->output);
    while (sp->cur < sp->ptr->width)
        sp->cur += sp->ptr->width - sp->cur;
    while (sp->ptr->width > q1)
    {
        if (sp->ptr->zero == FALSE)
            ft_putchar(' ');
        if (sp->ptr->zero == TRUE)
            ft_putchar('0');
        sp->ptr->width--;
    }
}

// char	*ft_ultoa(long n)
// {
// 	char			*s;
// 	long	nb;
// 	int				len;

// 	len = 1;
// 	n < 0 ? ++len : 0;
// 	nb = n < 0 ? -n : n;
// 	while (nb > 9)
// 	{
// 		nb /= 10;
// 		++len;
// 	}
// 	s = (char*)malloc(sizeof(char) * (len + 1));
// 	s[len] = '\0';
// 	n < 0 ? *s = '-' : 0;
// 	n < 0 ? n = -n : 0;
// 	while (n > 9)
// 	{
// 		s[--len] = (n % 10) + 48;
// 		n /= 10;
// 	}
// 	s[--len] = n + 48;
// 	return (s);
// }
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