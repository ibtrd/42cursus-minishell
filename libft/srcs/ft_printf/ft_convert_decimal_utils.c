/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_decimal_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:17:04 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/19 06:47:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pf_decimal_maths(t_format *format, int nbr)
{
	size_t	max;
	int		sign;

	max = 0;
	format->arglen = ft_itoalen(nbr) - (nbr < 0);
	if (format->arglen > format->precision)
		max = format->arglen;
	else
	{
		max = format->precision;
		format->precisionlen = format->precision - format->arglen;
	}
	sign = (format->plus) + (format->blank) + (nbr < 0);
	if (format->width > max)
		format->padlen = format->width - max - sign;
	format->totallen = max + format->padlen + sign;
}

size_t	pf_decimal_place_sign(char *print, t_format *format, int nbr)
{
	size_t	i;

	i = 0;
	if (!format->zero)
	{
		ft_memset(print + i, ' ', format->padlen);
		i = format->padlen;
	}
	if (nbr < 0)
		i = ft_strlcat(print, "-", format->totallen + 1);
	else if (format->plus)
		i = ft_strlcat(print, "+", format->totallen + 1);
	else if (format->blank)
		i = ft_strlcat(print, " ", format->totallen + 1);
	if (format->zero)
		ft_memset(print + i, '0', format->padlen);
	return (i);
}

size_t	pf_decimal_place_sign_left(char *print, t_format *format, int nbr)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
		i = ft_strlcat(print, "-", format->totallen + 1);
	else if (format->plus)
		i = ft_strlcat(print, "+", format->totallen + 1);
	else if (format->blank)
		i = ft_strlcat(print, " ", format->totallen + 1);
	if (format->precisionlen)
	{
		ft_memset(print + i, '0', format->precisionlen);
		i += format->precisionlen;
	}
	return (i);
}
