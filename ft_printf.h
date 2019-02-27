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
	int		cur;
	int		x;
	int		a;
	int		rtn;
	int     arr;
	int 	post;
	unsigned int ant;
	char	*output;
	va_list arg;
	t_adds	*ptr;
}				t_whole;

//main func
int			ft_printf(const char *format, ...);
int			parse(const char *format, t_whole *sp);
int         ft_flags(const char *format, t_whole *sp);
int        	check_flags(t_whole *sp);
// add funcs
void        check_str(t_whole *sp);
void        check_digit(t_whole *sp);
void        check_hex(t_whole *sp);
void	    check_char(t_whole *sp);
void    	check_octal(t_whole *sp);
void      	check_per(t_whole *sp);
void        check_bighex(t_whole *sp);
void        check_unsigned(t_whole *sp);
void    	check_point(t_whole *sp);
void    	check_binary(t_whole *sp);
void    	check_prec(t_whole *sp);
void        ft_len(const char *format, t_whole *sp);
//width
void        ft_width(const char *format, t_whole *sp);
void        oct_width(t_whole *sp);
void     	int_width(t_whole *sp);
void    	per_width(t_whole *sp);
void       	get_width(t_whole *sp);
void        str_width(t_whole *sp);
void        hex_width(t_whole *sp);
void    	point_width(t_whole *sp);
void        u_width(t_whole *sp);
void    	binary_width(t_whole *sp);
// boolean funcs
void    	ft_minus(const char *format, t_whole *sp);
void    	ft_plus(const char *format, t_whole *sp);
void    	ft_setzero(const char *format, t_whole *sp);
void    	ft_hash(const char *format, t_whole *sp);
void    	ft_space(const char *format, t_whole *sp);
void    	ft_star(const char *format, t_whole *sp);
void        ft_prec(const char *format, t_whole *sp);
//libft/helpers
char		*ft_itoa(int nbr);
char		*ft_uitoa_base(unsigned int val, int base);
char		*ft_ulltoa_base(unsigned long long val, int base);
void		ft_putchar(char c);
void    	ft_putstr(char *str);
int			mod_strchr(char c, char *s1);
void		ft_putnbr(int n);
int     	num_len(int c);
int     	ft_strlen(char *str);
char		*ft_strnew(size_t n);
char		*ft_strdup(const char *s1);
void		*ft_memset(void *a, int b, size_t n);
int			ft_nbr_len(int n);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_uitoa_bigbase(unsigned int val, int base);
void		ft_strdel(char **as);
char		*ft_ultoa(unsigned long n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
//initialize
void    	ft_zero(t_adds *ptr);

#endif
