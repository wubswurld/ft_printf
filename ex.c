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

char	*ft_ltoa(long n)
{
	char	*s;
	long	nb;
	int		len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = 1;
	n < 0 ? ++len : 0;
	nb = n < 0 ? -n : n;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n > 9)
	{
		s[--len] = (n % 10) + 48;
		n /= 10;
	}
	s[--len] = n + 48;
	return (s);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		neg;
	int		x;

	x = ft_nbr_len(nbr);
	neg = 0;
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (!(str = ft_strnew(x + 1)))
		return (NULL);
	if (nbr < 0)
	{
		neg = 1;
		str[0] = '-';
		nbr *= -1;
	}
	while (x >= neg)
	{
		str[x] = (nbr % 10) + 48;
		nbr /= 10;
		x--;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

void      check_char(t_whole *sp)
{  
    char pst;
    
    pst = va_arg(sp->arg, int);
    // if (!pst || ft_isdigit(pst))
    // {
    //     ft_putstr("(null)");
    //     return ;
    // }
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
    if (!sp->ptr->len || sp->ptr->len == 1 || sp->ptr->len == 2 || sp->ptr->len == 3 || sp->ptr->len == 4)
        hex_lenmod(sp);
    sp->cur = ft_strlen(sp->output);
    // if (sp->ptr->hash == TRUE && !sp->post)
    //     sp->cur -= 2;
    if (sp->ptr->tmp == 'x' && sp->ptr->minus == FALSE)
    {
        hex_width(sp);
        if (sp->ptr->hash == TRUE && sp->post != 0)
            write(1, "0x", 2);
        ft_putstr(sp->output);
    }
    if (sp->ptr->tmp == 'x' && sp->ptr->minus == TRUE) 
    {
        if (sp->ptr->hash == TRUE && sp->post != 0)
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
    sp->cur = ft_strlen(sp->output);
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

void      check_per(t_whole *sp)
{
    check_prec(sp);
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

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t z;

	z = 0;
	while (z < n)
	{
		((char *)s1)[z] = ((char *)s2)[z];
		z++;
	}
	return (s1);
}