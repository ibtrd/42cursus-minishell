/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:55:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/18 22:14:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_set(t_vector *v, size_t index, void *item)
{
	int	status;

	if (!v)
		return (FAILURE);
	status = UNDEFINED;
	if (index < v->total)
	{
		ft_memcpy(v->ptr + index * v->size, item, v->size);
		status = SUCCESS;
	}
	return (status);
}
