/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addconversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:27:49 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/08 15:16:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "ft_printf_err.h"

static int	convert_string(t_vector *buffer, va_list *args);
static int	convert_percent(t_vector *buffer, va_list *args);

int	add_conversion(char specifier, t_vector *buffer, va_list *args)
{
	const t_convert	converter[] = {convert_string, convert_percent};
	const char		cmp[] = {'s', '%', '\0'};
	int				i;

	i = 0;
	while (cmp[i])
	{
		if (specifier == cmp[i])
			return (converter[i](buffer, args));
		i++;
	}
	return (FAILURE);
}

static int	convert_string(t_vector *buffer, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	return (ft_vector_join(buffer, str, ft_strlen(str)));
}

static int	convert_percent(t_vector *buffer, va_list *args)
{
	(void)args;
	return (ft_vector_add(buffer, "%"));
}
