/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uilltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:17:05 by jawatter          #+#    #+#             */
/*   Updated: 2019/03/01 13:17:23 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa_base(unsigned long val, int base)
{
	// max base of 16 is = to 0123456789abcdef
	static char tmp[] = "0123456789abcdef";
	static char buf[65];
	char		*ptr;

	ptr = &buf[64];
	*ptr = '\0';
	if (val == 0)
	{	
		*--ptr = tmp[val % base];
		val = val / base;
	}
	while (val != 0)
	{
		*--ptr = tmp[val % base];
		val = val / base;
	}
	return (ptr);
}
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	if (!(s1 = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(s1, s + start, len));
}

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n && s2[x])
	{
		s1[x] = s2[x];
		x++;
	}
	while (x < n)
	{
		s1[x] = '\0';
		x++;
	}
	return (s1);
}