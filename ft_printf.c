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

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int			ft_flags(const char *format, va_list arg)
{
	int x;

	x = 0; 
	while (format[x] == '%')
	{
		if (format[x + 1] == 's' || format[x + 1] == 'S')
		{

		}
	}
}
int			parse(const char *format, va_list arg)
{
	int		x;

	x = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			x++;
		}
		if (*format == '%')
		{
			ft_flags(format, arg);
		}
		format++;
	}
	return (x);
}
int			ft_printf(const char *format, ...)
{
	int		x;
	va_list	arg;

	va_start(arg, format);
	t_adds = seto();
	x = parse(format, arg);
	va_end(arg);
	return (x);
}
int main ()
{
	ft_printf("lol\nlol\n");
}
