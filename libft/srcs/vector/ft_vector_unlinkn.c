/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_unlinkn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:45:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 13:41:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_unlinkn(t_vector *v, size_t index, size_t n, void *ptr)
{
	if (!v || index >= v->total || index + n > v->total || !ptr)
		return (FAILURE);
	if (!n)
		return (SUCCESS);
	ft_vector_copyn(v, index, n, ptr);
	ft_memcpy(v->ptr + index * v->size, v->ptr + (index + n) * v->size,
		(v->total - n - index) * v->size);
	v->total -= n;
	while (v->capacity > 1 && v->total <= (v->capacity >> 2))
		if (ft_vector_resize(v, v->capacity >> 1))
			return (FAILURE);
	return (SUCCESS);
}
