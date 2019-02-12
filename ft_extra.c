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

char	*ft_itoa_base(int val, int base)
{
	// max base of 16 is = to 0123456789abcdef
	static char tmp[] = "0123456789abcdef";
	static char buf[65];
	char		*ptr;

	ptr = &buf[64];
	*ptr = '\0';
	if (val < 0 && base == 10)
		val = val * -1;
	if (val == 0)
		*--ptr = tmp[val % base];
	while (val != 0)
	{
		*--ptr = tmp[val % base];
		val = val / base;
	}
	if (val < 0)
		*--ptr = '-';
	return (ptr);
}