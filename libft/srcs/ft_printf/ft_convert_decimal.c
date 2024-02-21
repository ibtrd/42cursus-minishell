/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:04:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:53:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

ssize_t	pf_convert_decimal(va_list *args, t_format *format)
{
	int		nbr;

	if (format->minus || format->period)
		format->zero = false;
	if (format->plus)
		format->blank = false;
	nbr = va_arg(*args, int);
	if (nbr < 0)
	{
		format->plus = false;
		format->blank = false;
	}
	if (nbr == 0 && format->period && format->precision < 1)
		return (pf_print_decimal_zero(format));
	pf_decimal_maths(format, nbr);
	if (format->minus)
		return (pf_print_decimal_left(format, nbr));
	return (pf_print_decimal(format, nbr));
}

ssize_t	pf_print_decimal(t_format *format, int nbr)
{
	char	*print;
	char	*itoa;
	ssize_t	wr;
	size_t	i;

	print = ft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	i = pf_decimal_place_sign(print, format, nbr);
	ft_memset(print + i, '0', format->precisionlen);
	wr = -1;
	itoa = ft_itoa(nbr);
	if (itoa)
	{
		i = ft_strlcat(print, itoa + (nbr < 0), format->totallen + 1);
		wr = write(format->fd, print, format->totallen);
	}
	free(print);
	free(itoa);
	return (wr);
}

ssize_t	pf_print_decimal_left(t_format *format, int nbr)
{
	char	*print;
	char	*itoa;
	ssize_t	wr;
	size_t	i;

	print = ft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	i = pf_decimal_place_sign_left(print, format, nbr);
	wr = -1;
	itoa = ft_itoa(nbr);
	if (itoa)
	{
		i = ft_strlcat(print, itoa + (nbr < 0), format->totallen + 1);
		ft_memset(print + i, ' ', format->padlen);
		wr = write(format->fd, print, format->totallen);
	}
	free(print);
	free(itoa);
	return (wr);
}

ssize_t	pf_print_decimal_zero(t_format *format)
{
	char	*print;
	ssize_t	wr;

	if (!format->width)
		return (0);
	print = ft_calloc(format->width + 1, sizeof(char));
	if (!print)
		return (-1);
	ft_memset(print, ' ', format->width);
	wr = write(format->fd, print, format->width);
	free(print);
	return (wr);
}
