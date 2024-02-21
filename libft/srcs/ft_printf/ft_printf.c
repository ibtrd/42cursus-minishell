/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:20:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:50:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	ssize_t	total_wr;
	ssize_t	wr;
	size_t	i;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	total_wr = 0;
	while (str[i])
	{
		wr = pf_reading_head(1, str + i, &args);
		if (wr == -1)
			break ;
		total_wr += wr;
		if (str[i] != '%')
			i += wr;
		else
			i += pf_argument_len(str + i + 1);
	}
	va_end(args);
	if (wr == -1)
		return (-1);
	return (total_wr);
}

ssize_t	pf_reading_head(int fd, const char *str, va_list *args)
{
	size_t		wr;
	t_format	format;

	format.fd = fd;
	if (*str != '%')
		return (pf_putstr_to_percent(str, format.fd));
	pf_init_format_struct(&format);
	format.type = pf_get_type(str + 1);
	if (!format.type)
		return (-1);
	pf_format_flags(str + 1, &format);
	pf_format_values(str + 1, &format, args);
	if ((int)format.width < 0)
		format.width *= -1;
	if ((int)format.precision < 0)
		format.precision = 0;
	if (format.width > FIELD_MAX || format.precision > FIELD_MAX)
		return (-1);
	wr = pf_converter(args, &format);
	return (wr);
}

ssize_t	pf_converter(va_list *args, t_format *format)
{
	if (format->type == 'c')
		return (pf_convert_char(args, format));
	else if (format->type == 's')
		return (pf_convert_string(args, format));
	else if (format->type == 'p')
		return (pf_convert_pointer(args, format));
	else if (format->type == 'd' || format->type == 'i')
		return (pf_convert_decimal(args, format));
	else if (format->type == 'u')
		return (pf_convert_unsigned_decimal(args, format));
	else if (format->type == 'x')
		return (pf_convert_lower_hexa(args, format));
	else if (format->type == 'X')
		return (pf_convert_upper_hexa(args, format));
	if (format->type == '%')
		return (pf_convert_percent(format->fd));
	return (-1);
}

int	pf_argument_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_ischarset(str[i], TYPE_SET))
		i++;
	return (i + 2);
}

int	pf_putstr_to_percent(const char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (write(fd, str, i));
}
