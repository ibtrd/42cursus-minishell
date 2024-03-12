/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:16 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:02:22 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_char(t_vector *buffer, va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	return (ft_vector_add(buffer, &c));
}
