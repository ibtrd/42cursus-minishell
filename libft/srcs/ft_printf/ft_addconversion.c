/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addconversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:27:49 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 16:58:38 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_conversion(char specifier, t_vector *buffer, va_list *args)
{
	const t_convert	converter[] = {
		convert_string,
		convert_percent,
		convert_char,
		convert_int,
		convert_int,
		convert_uint,
		convert_hexlow,
		convert_hexup
	};
	const char		cmp[] = {'s', '%', 'c', 'd', 'i', 'u', 'x', 'X', '\0'};
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
