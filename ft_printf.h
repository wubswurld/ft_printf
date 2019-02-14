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
	int		a;
	int		rtn;
	char	*output;
	va_list arg;
	t_adds	*ptr;
}				t_whole;

//main func
int			ft_printf(const char *format, ...);
int			parse(const char *format, t_whole *sp);
// add funcs
int         ft_flags(const char *format, t_whole *sp);
int         check_str(t_whole *sp);
int         check_digit(t_whole *sp);
void       	get_width(t_whole *sp);
void        check_hex(t_whole *sp);
void		numcount(const char *format, t_whole *sp);
void	    check_char(t_whole *sp);
// boolean funcs
void    	ft_minus(const char *format, t_whole *sp);
void    	ft_plus(const char *format, t_whole *sp);
void    	ft_setzero(const char *format, t_whole *sp);
void    	ft_hash(const char *format, t_whole *sp);
void    	ft_space(const char *format, t_whole *sp);
void        ft_width(const char *format, t_whole *sp);
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
int			ft_toupper(int c);
char		*ft_itoa_base(int val, int base);
int			ft_isdigit(int c);
//initialize
void    ft_zero(t_adds *ptr);

#endif
