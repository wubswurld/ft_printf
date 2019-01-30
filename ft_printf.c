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

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	(*func_ptr)(const char*, t_adds, int*, va_list);

int			check_flag(t_adds ptr, va_list arg)
{

}
int			ft_flags(const char *format, t_adds ptr, int *x, va_list arg)
{
	//x is a int ptr so x automatically refreshes in each other function
	while (mod_strchr(format[*x], "sSpdDioOuUxXcC") < 0 && format[*x] == '\0')
	{
		break ;
	}
	//saves coversion char following the '%'
	ptr->type = format[*x];
	return(check_flag(ptr, arg));
}

int			parse(const char *format, t_adds ptr, va_list arg)
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
			 rtn += ft_flags(format, ptr, arg, &x);
			 seto(&ptr);
		}
		x++;
	}
	return (rtn);
}

int			ft_printf(const char *format, ...)
{
	int		rtn;
	va_list	arg;
	t_adds	ptr;

//inizilize arg to  
	va_start(arg, format);
	seto(&ptr);
	rtn = parse(format, ptr, arg);
	va_end(arg);
	return (rtn);
}
int main ()
{
	ft_printf("lollol\n");
	printf("lollol\n");
}
