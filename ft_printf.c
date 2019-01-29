/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:41:41 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/25 23:44:31 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
void	(*func_ptr)(const char*, t_adds, int*, va_list);
void	(*func_ptr1)(const char*, t_adds, int*, va_list);

int			ft_flags(const char *format, t_adds adds, int *x, va_list arg)
{
	//x is a int ptr so x automatically refreshes in each other function
	(*func_ptr)(format[*i])
}

int			parse(const char *format, t_adds adds, va_list arg)
{
	int		x;
	int 	rtn;

	x = 0;
	rtn = 0;
	while (format[x])
	{
		if (format[x] != '%')
		{
			ft_putchar(format[x]);
			rtn++;
		}
		if (*format == '%')
		{
			//save address of x so you know what position of the '%'; 
			rtn += ft_flags(format, adds, arg, &x);
			adds = seto();
		}
		x++;
	}
	return (rtn);
}

int			ft_printf(const char *format, ...)
{
	int		rtn;
	va_list	arg;
	t_adds	adds;
	int	(*func_ptr1)(const char*, t_adds, int*, va_list);
	func_ptr1 = &parse

	va_start(arg, format);
	adds = seto();
	rtn = parse(format, adds, arg);
	va_end(arg);
	return (rtn);
}
int main ()
{
	ft_printf("lol\nlol\n");
	printf("lol\nlol\n");
}
