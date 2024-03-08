/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:38:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 15:33:02 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static int	build_buffer(const char *str, t_vector *buffer, va_list *args);
static int	print_buffer(int fd, t_vector *buffer);

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list		args;
	t_vector	buffer;

	if (!str || ft_vector_init(&buffer, sizeof(char), 0))
		return (FAILURE);
	va_end(args);
	va_start(args, str);
	if (build_buffer(str, &buffer, &args))
	{
		va_end(args);
		ft_vector_free(&buffer, NULL);
		return (FAILURE);
	}
	va_end(args);
	return (print_buffer(fd, &buffer));
}

static int	build_buffer(const char *str, t_vector *buffer, va_list *args)
{
	int		status;
	char	c;

	status = SUCCESS;
	c = *str++;
	while (c && !status)
	{
		if (c != '%')
			status = ft_vector_add(buffer, &c);
		else
		{
			status = add_conversion(*str, buffer, args);
			str++;
		}
		c = *str++;
	}
	return (status);
}

static int	print_buffer(int fd, t_vector *buffer)
{
	ssize_t	status;

	status = write(fd, buffer->ptr, buffer->total);
	ft_vector_free(buffer, NULL);
	return (status);
}
