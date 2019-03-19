/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:45:42 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/15 13:45:54 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_prec(const char *format, t_whole *sp)
{
    // if (format[sp->x + 1] == '.' && format[sp->x + 2] == '*')
    // {    
    //     sp->ptr->precision = va_arg(sp->arg, int);
    //     printf("%d", sp->ptr->precision);
    //     sp->x++;
    // }
    // if (format[sp->x + 1] == '.' && format[sp->x + 2])
    //     ++sp->x;
    // if (format[sp->x + 1] == '.' && format[sp->x + 2] == 'c')
    //     sp->x++;
    if (format[sp->x + 1] == '.')
    {
        ++sp->x;
        sp->ptr->precision = ft_atoi(&format[sp->x + 1]);
        while (ft_isdigit(format[sp->x]))
            ++sp->x;
    }
    sp->x++;
    // if (format[sp->x + 1] == '.' && format[sp->x + 2] >= 0)
    //     ++sp->x;
    // else
    // {
    //     sp->ptr->precision = FALSE;
    //     sp->x++;
    // }
}

void    check_prec(t_whole *sp)
{
    char *new;
    int len2;
    int x;
    //int len;

    x = 0; 
    len2 = ft_strlen(sp->output);
    if (sp->ptr->tmp == 'u' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    {
        if (sp->ptr->precision == 0)
        {
            ft_putchar(' ');
            sp->output[0] = '\0';
        }   
    }
    if (sp->ptr->tmp == 's' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    {
        // if (sp->ptr->precision > ft_strlen(sp->output))
        //     sp->ptr->precision = sp->ptr->precision - ft_strlen(sp->output);
        new = ft_strnew(sp->ptr->precision + 1);
        new = ft_memcpy(new, sp->output, sp->ptr->precision);
        free(sp->output);
        sp->output = new;
        sp->cur = ft_strlen(new);
    }
    if (sp->ptr->tmp == 'x' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    {
        if (sp->ptr->precision == 0)
        {
            ft_putchar(' ');
            sp->output[0] = '\0';
        }
        //new = ft_strnew(sp->ptr->precision + 1);
    }
    // if (sp->ptr->tmp == 'd' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    // {
    //      if (sp->ptr->precision == 0)
    //     {
    //         ft_putchar(' ');
    //         sp->output[0] = '\0';
    //     }
    // }
    if (sp->ptr->tmp =='o' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    {
        if (sp->ptr->hash == TRUE)
        {
            ft_putchar('0');
            sp->cur += 2;
        }
        if (sp->ptr->precision == 0)
        {
            ft_putchar(' ');
            sp->output[0] = '\0';
            //return ;
        }
    }
}
//     if (sp->ptr->tmp == 'c' && sp->ptr->precision >= 0)
//     {
//         ++sp->x;
//     }
// }

void    prec_int(t_whole *sp)
{
    int q;
    int length;
    char *str;
    char *str2;
    
    q = 0;
    length = ft_strlen(sp->output);
    if (sp->ptr->tmp == 'd' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    {
            if (sp->ptr->precision == 0)
                sp->output[0] = ' ';
            if (sp->ptr->precision > length)
            {
                q = sp->ptr->precision - length;
                str = ft_strnew(q);
                while (q-- > 0)
                    str[q] = '0';
                str2 = ft_strjoin(str, sp->output);
                free(str);
                free(sp->output);
                sp->output = str2;
            }
    }   
}
void    prec_unsigned(t_whole *sp)
{
    int q;
    int length;
    char *str;
    char *str2;
    q = 0;
    length = 0;
    if (sp->ptr->tmp == 'u' && sp->ptr->precision >= 0 && sp->ptr->precision < ft_strlen(sp->output))
    {
            if (sp->ptr->precision == 0)
            {
                ft_putchar(' ');
                //sp->output[0] = '\0';
            }
            if (sp->ptr->precision > length)
            {
                q =  sp->ptr->precision - length;
                str = ft_strnew(q);
                while (q-- > 0)
                    str[q] = '0';
                str2 = ft_strjoin(str, sp->output);
                free(str);
                free(sp->output);
                sp->output = str2;
            }
    }   
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	char	*s3;

	x = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
		return (NULL);
	ft_strcpy((char *)s3, (char *)s1);
	s3 = ft_strcat((char *)s3, (char *)s2);
	return (s3);
}
char	*ft_strcat(char *s1, char *s2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (s1[y] != '\0')
	{
		y++;
	}
	while (s2[x] != '\0')
	{
		s1[y + x] = s2[x];
		x++;
	}
	s1[x + y] = '\0';
	return (s1);
}
char	*ft_strcpy(char *s1, char *s2)
{
	int		x;

	x = 0;
	while (s2[x] != '\0')
	{
		s1[x] = s2[x];
		x++;
	}
	s1[x] = '\0';
	return (s1);
}