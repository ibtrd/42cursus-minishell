/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:02 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/19 06:48:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pf_pointer_maths(t_format *format, unsigned long long ptr)
{
	size_t	max;
	int		prefix;

	format->arglen = ft_ulltoalen_base(ptr, LOWER_HEXA);
	max = format->arglen;
	if (format->period && format->precision > format->arglen)
	{
		max = format->precision;
		format->precisionlen = format->precision - format->arglen;
	}
	prefix = (format->plus) + (format->blank);
	if (format->width > max + 2)
		format->padlen = format->width - max - 2 - prefix;
	format->totallen = max + format->padlen + 2 + prefix;
}

void	pf_nil_pointer_maths(t_format *format)
{
	format->arglen = 5;
	format->period = false;
	if (format->width > format->arglen)
		format->padlen = format->width - format->arglen;
	format->totallen = format->arglen + format->padlen;
}
