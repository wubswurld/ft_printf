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

#include "printf.h"

t_adds  seto(void)
{
    t_adds adds;
    adds->plus = FALSE;
    adds->minus = FALSE;
    adds->zero = FALSE;
    adds->space = FALSE;
    adds->hash = FALSE;
    adds->tmp = FALSE;
    adds->len = FALSE;
    adds->width = FALSE;
    adds->precision = FALSE;
    return (adds);
}