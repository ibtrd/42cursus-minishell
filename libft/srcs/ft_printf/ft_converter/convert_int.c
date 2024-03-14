/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:44 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:11:13 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_integer.h"
#include "ft_string.h"
#include <stdlib.h>

int	convert_int(t_vector *buffer, va_list *args)
{
	int		nb;
	char	*str;
	int		error;

	nb = va_arg(*args, int);
	str = ft_itoa(nb);
	if (!str)
		return (FAILURE);
	error = ft_vector_join(buffer, str, ft_strlen(str));
	free(str);
	return (error);
}
