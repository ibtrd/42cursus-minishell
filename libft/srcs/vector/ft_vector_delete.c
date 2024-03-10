/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:25:25 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 14:47:58 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"
#include <stddef.h>

int	ft_vector_delete(t_vector *v, size_t index)
{
	if (!v || index >= v->total)
		return (FAILURE);
	if (v->del)
		v->del((void **)ft_vector_get(v, index));
	ft_memcpy(v->ptr + index * v->size, v->ptr + (index + 1) * v->size,
		(v->total - 1 - index) * v->size);
	v->total--;
	if (v->total > 0 && v->total == (v->capacity >> 2))
		return (ft_vector_resize(v, v->capacity >> 1));
	return (SUCCESS);
}
