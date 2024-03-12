/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:45:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 11:23:35 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_unlink(t_vector *v, size_t index)
{
	if (!v || index >= v->total)
		return (FAILURE);
	ft_memcpy(v->ptr + index * v->size, v->ptr + (index + 1) * v->size,
		(v->total - 1 - index) * v->size);
	v->total--;
	if (v->total > 0 && v->total == (v->capacity >> 2))
		return (ft_vector_resize(v, v->capacity >> 1));
	return (SUCCESS);
}
