/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:26:34 by jawatter          #+#    #+#             */
/*   Updated: 2019/01/26 15:26:49 by jawatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  seto(t_adds *ptr)
{   
    ptr->plus = FALSE;
    ptr->minus = FALSE;
    ptr->zero = FALSE;
    ptr->space = FALSE;
    ptr->hash = FALSE;
    ptr->tmp = FALSE;
    ptr->len = FALSE;
    ptr->width = FALSE;
    ptr->precision = FALSE;
 }