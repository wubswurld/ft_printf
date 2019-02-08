/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:57:27 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/31 19:57:29 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putstr(char *str)
{
    int x;

    x = 0;
    while (str[x])
    {
        ft_putchar(str[x]);
        x++;
    }
}

int     ft_strlen(char *str)
{
    int x;

    x = 0;
    while (str[x])
        return (x++);
    return (x);
}

int     num_len(int c)
{
    int x;

    x = 0;
    while (c)
    {
        c /= 10;
        x++;
    }
    return (x);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int	    mod_strchr(char c, char *s1)
{
    int     a;

    a = 0;
    while (s1[a])
    {
        if (s1[a] == c)
            return (1);
        a++;
    }
    return (0);
}

char	*ft_strdup(const char *s1)
{
	int		x;
	int		a;
	char	*tmp;

	a = 0;
	while (s1[a])
		a++;
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (a + 1))))
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		tmp[x] = s1[x];
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}

char	*ft_strnew(size_t n)
{
	char *tmp;

	if (!(tmp = (char *)malloc(n + 1)))
		return (NULL);
	ft_memset(tmp, 0, n + 1);
	return (tmp);
}

void	*ft_memset(void *a, int b, size_t n)
{
	size_t x;

	x = 0;
	b = ((unsigned char)b);
	while (x < n)
	{
		((unsigned char *)a)[x] = ((unsigned char)b);
		x++;
	}
	return (a);
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

int		ft_nbr_len(int n)
{
	int neg;
	int x;

	neg = 0;
	x = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	while (n / 10)
	{
		x++;
		n /= 10;
	}
	return ((x + neg));
}

int		ft_atoi(const char *str)
{
	int num;
	int neg;
	int x;

	x = 0;
	neg = 1;
	num = 0;
	while ((str[x] == '\t') || (str[x] == '\n') || (str[x] == '\v') ||
			(str[x] == '\f') || (str[x] == '\r') || (str[x] == ' '))
		x++;
	if (str[x] == '-')
	{
		neg = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while ((str[x] >= '0') && (str[x] <= '9') && (str[x] != '\0'))
	{
		num = (num * 10 + str[x] - '0');
		x++;
	}
	return (num * neg);
}
