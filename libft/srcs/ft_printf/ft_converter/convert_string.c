/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:52:08 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:02:30 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

int	convert_string(t_vector *buffer, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str)
		return (ft_vector_join(buffer, str, ft_strlen(str)));
	return (ft_vector_join(buffer, "(null)", 6));
}
