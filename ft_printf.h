/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:44:12 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/25 23:32:09 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <unistd.h>

//boolean
# define TRUE 1
# define FALSE 0

//sSpdDioOUxXcC
//# define FLAGS(c) (c == 'c')
//structs
typedef struct s_adds
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	char	tmp;
	int		len;
	int		width;
	int		precision;
} 				t_adds;

typedef	struct s_whole
{
	int		x;
	int		rtn;
	va_list arg2;
	va_list arg;
	t_adds	*ptr;
}				t_whole;

//main func
int		ft_printf(const char *format, ...);
int			parse(const char *format, t_whole *sp);
//libft/helpers
void	ft_putchar(char c);
char	mod_strchr(char c, char *s1);
//initialize
void    ft_zero(t_adds *ptr);

#endif
