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
    if (sp->ptr->len == 1)
        sp->output = ft_itoa((short)sp->arr);
    else if (sp->ptr->len == 0)
        sp->output = ft_itoa(sp->arr);
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == FALSE)
    {
        int_width(sp);
        if (sp->ptr->plus == TRUE && sp->arr > 0)
            ft_putchar('+');
        ft_putstr(sp->output);
        //ft_putnbr(sp->arr);
    }
    if ((sp->ptr->tmp == 'd' || sp->ptr->tmp == 'i') && sp->ptr->minus == TRUE)
    {
        ft_putstr(sp->output);
        //ft_putnbr(sp->arr);
        int_width(sp);
    }
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
    sp->rtn += ft_strlen(sp->output);
}

void    check_prec(t_whole *sp)
{
    char *new;

    if (sp->ptr->tmp == 's' && sp->ptr->precision >= 0)
    {
        new = ft_strnew(sp->ptr->precision + 1);
        ft_memcpy(new, sp->output, sp->ptr->precision);
        free(sp->output);
        sp->output = new;
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