/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mostbasic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:48:47 by jawatter          #+#    #+#             */
/*   Updated: 2019/02/09 13:48:59 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}