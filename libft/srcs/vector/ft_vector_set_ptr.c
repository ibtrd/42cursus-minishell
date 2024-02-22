/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:55:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 18:23:03 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_set_ptr(t_vector *v, size_t index, void *item)
{
	int	status;

	if (!v)
		return (FAILURE);
	status = UNDEFINED;
	if (index < v->total)
	{
		*((char **)v->ptr + index) = item;
		status = SUCCESS;
	}
	return (status);
}
