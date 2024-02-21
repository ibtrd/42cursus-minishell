/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned_decimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:27:25 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:54:00 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

ssize_t	pf_convert_unsigned_decimal(va_list *args, t_format *format)
{
	unsigned int		nbr;

	if (format->minus || format->precision)
		format->zero = false;
	if (format->plus)
		format->blank = false;
	nbr = va_arg(*args, unsigned int);
	pf_unsigned_decimal_maths(format, nbr);
	if (nbr == 0 && format->period && format->precision < 1)
		return (pf_print_decimal_zero(format));
	if (format->minus)
		return (pf_print_unsigned_decimal_left(format, nbr));
	return (pf_print_unsigned_decimal(format, nbr));
}

ssize_t	pf_print_unsigned_decimal(t_format *format, unsigned int nbr)
{
	char	*print;
	char	*itoa;
	ssize_t	wr;
	size_t	i;

	print = ft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	if (format->zero)
		ft_memset(print, '0', format->padlen);
	else
		ft_memset(print, ' ', format->padlen);
	i = format->padlen;
	ft_memset(print + i, '0', format->precisionlen);
	wr = -1;
	itoa = ft_uitoa_base(nbr, DECIMAL);
	if (itoa)
	{
		i = ft_strlcat(print, itoa, format->totallen + 1);
		wr = write(format->fd, print, format->totallen);
	}
	free(print);
	free(itoa);
	return (wr);
}

ssize_t	pf_print_unsigned_decimal_left(t_format *format, unsigned int nbr)
{
	char	*print;
	char	*itoa;
	ssize_t	wr;
	size_t	i;

	print = ft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	ft_memset(print, '0', format->precisionlen);
	wr = -1;
	itoa = ft_uitoa_base(nbr, DECIMAL);
	if (itoa)
	{
		i = ft_strlcat(print, itoa, format->totallen + 1);
		ft_memset(print + i, ' ', format->padlen);
		wr = write(format->fd, print, format->totallen);
	}
	free(print);
	free(itoa);
	return (wr);
}

void	pf_unsigned_decimal_maths(t_format *format, unsigned int nbr)
{
	size_t	max;

	max = 0;
	format->arglen = ft_uitoalen_base(nbr, DECIMAL);
	if (format->arglen > format->precision)
		max = format->arglen;
	else
	{
		max = format->precision;
		format->precisionlen = format->precision - format->arglen;
	}
	if (format->width > max)
		format->padlen = format->width - max;
	format->totallen = max + format->padlen;
}
