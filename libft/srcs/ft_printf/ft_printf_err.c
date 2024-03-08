/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:38:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 04:58:33 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

#include "ft_printf_err.h"

static int	build_buffer(const char *str, t_vector *buffer, va_list *args);
static int	print_buffer(t_vector *buffer);
static int	add_errno(t_vector *buffer, int err);

int	ft_printf_err(int err, const char *str, ...)
{
	va_list		args;
	t_vector	buffer;

	if (!str || ft_vector_init(&buffer, sizeof(char), 0))
		return (FAILURE);
	va_end(args);
	va_start(args, str);
	if (build_buffer(str, &buffer, &args) || add_errno(&buffer, err))
	{
		va_end(args);
		ft_vector_free(&buffer, NULL);
		return (FAILURE);
	}
	va_end(args);
	return (print_buffer(&buffer));
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

static int	add_errno(t_vector *buffer, int err)
{
	const char	*str = strerror(err);
	char		c;

	if (ft_vector_join(buffer, ": ", 2))
		return (FAILURE);
	c = *str++;
	while (c)
	{
		if (ft_vector_add(buffer, &c))
			return (FAILURE);
		c = *str++;
	}
	if (ft_vector_join(buffer, "\n\0", 2))
		return (FAILURE);
	return (SUCCESS);
}

static int	print_buffer(t_vector *buffer)
{
	ssize_t	status;

	status = write(STDERR_FILENO, buffer->ptr, buffer->total);
	ft_vector_free(buffer, NULL);
	return (status);
}
