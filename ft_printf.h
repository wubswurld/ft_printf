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

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

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

int		ft_printf(const char *format, ...);

#endif
