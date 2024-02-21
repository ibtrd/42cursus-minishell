/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:22:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:52:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

ssize_t	pf_convert_string(va_list *args, t_format *format)
{
	char	*string;

	string = va_arg(*args, char *);
	if (!string)
	{
		pf_null_string_maths(format);
		return (pf_print_null_string(format));
	}
	else
	{
		pf_string_maths(format, string);
		return (pf_print_string(format, string));
	}
}

ssize_t	pf_print_string(t_format *format, char *string)
{
	char	*print;
	ssize_t	wr;
	size_t	i;

	print = ft_calloc((format->totallen + 1), sizeof(char));
	if (!print)
		return (-1);
	i = 0;
	if (!format->minus)
	{
		ft_memset(print, ' ', format->padlen);
		i = format->padlen;
	}
	ft_strlcat(print, string, i + format->arglen + 1);
	if (format->minus)
	{
		i = format->arglen;
		ft_memset(print + i, ' ', format->padlen);
	}
	wr = write(format->fd, print, format->totallen);
	free(print);
	return (wr);
}

void	pf_string_maths(t_format *format, char *string)
{
	if (format->period)
		format->arglen = ft_strnlen(string, format->precision);
	else
		format->arglen = ft_strlen(string);
	if (format->width > format->arglen)
	{
		format->totallen = format->width;
		format->padlen = format->width - format->arglen;
	}
	else
		format->totallen = format->arglen;
}

ssize_t	pf_print_null_string(t_format *format)
{
	char	*print;
	ssize_t	wr;
	size_t	i;

	print = ft_calloc((format->totallen + 1), sizeof(char));
	if (!print)
		return (-1);
	i = 0;
	if (!format->minus)
	{
		ft_memset(print, ' ', format->padlen);
		i = format->padlen;
	}
	ft_strlcat(print, "(null)", i + format->arglen + 1);
	if (format->minus)
	{
		i = format->arglen;
		ft_memset(print + i, ' ', format->padlen);
	}
	wr = write(format->fd, print, format->totallen);
	free(print);
	return (wr);
}

void	pf_null_string_maths(t_format *format)
{
	if (!format->period || (format->period && format->precision > 5))
		format->arglen = 6;
	else
		format->arglen = 0;
	if (format->width > format->arglen)
	{
		format->totallen = format->width;
		format->padlen = format->width - format->arglen;
	}
	else
		format->totallen = format->arglen;
}
