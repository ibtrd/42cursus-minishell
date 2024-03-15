/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:25:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/15 03:10:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_merge(t_vector *v1, size_t index, t_vector *v2)
{
	if (!v1 || !v2 || index > v1->total || v1->size != v2->size)
		return (FAILURE);
	while (v1->total + v2->total > v1->capacity)
	{
		if (ft_vector_resize(v1, v1->capacity << 1))
			return (FAILURE);
	}
	ft_memmove(v1->ptr + v1->size * (index + v2->total),
		v1->ptr + v1->size * index, v1->size * (v1->total - index));
	ft_memcpy(v1->ptr + v1->size * index, v2->ptr, v2->size * v2->total);
	v1->total += v2->total;
	free(v2->ptr);
	return (SUCCESS);
}
