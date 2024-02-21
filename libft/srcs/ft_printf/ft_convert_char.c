/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:56:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:52:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "unistd.h"
#include "libft.h"
#include "ft_printf.h"

ssize_t	pf_convert_char(va_list *args, t_format *format)
{
	char	c;

	c = va_arg(*args, int);
	if (format->width > 1)
	{
		format->totallen = format->width;
		format->padlen = format->width - 1;
	}
	else
		format->totallen = 1;
	return (pf_print_char(format, c));
}

ssize_t	pf_print_char(t_format *format, char c)
{
	char	*print;
	size_t	i;
	ssize_t	wr;

	print = ft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	i = 0;
	if (format->minus == true)
		print[i++] = c;
	ft_memset(print + i, ' ', format->padlen);
	if (format->minus == false)
		print[format->totallen - 1] = c;
	print[format->totallen] = '\0';
	wr = write(format->fd, print, format->totallen);
	free(print);
	return (wr);
}
