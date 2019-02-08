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
	va_list arg;
	t_adds	*ptr;
	char	*tsp;
}				t_whole;

//main func
int			ft_printf(const char *format, ...);
int			parse(const char *format, t_whole *sp);
int         check_flags(t_whole *sp);
int         ft_flags(const char *format, t_whole *sp);
int         check_str(t_whole *sp);
int         check_digit(t_whole *sp);
int         get_width(t_whole *sp);
//libft/helpers
void		ft_putchar(char c);
void    	ft_putstr(char *str);
int			mod_strchr(char c, char *s1);
void		ft_putnbr(int n);
int     	num_len(int c);
int     	ft_strlen(char *str);
char		*ft_itoa(int nbr);
char		*ft_strnew(size_t n);
char		*ft_strdup(const char *s1);
void		*ft_memset(void *a, int b, size_t n);
int			ft_nbr_len(int n);
int			ft_atoi(const char *str);
//initialize
void    ft_zero(t_adds *ptr);

#endif
