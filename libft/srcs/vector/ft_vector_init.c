/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:50:49 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 14:44:28 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"
#include <stdlib.h>

int	ft_vector_init(t_vector *v,
	size_t data_size,
	size_t capacity,
	void (*del)(void **))
{
	if (!v || data_size < 1)
		return (FAILURE);
	if (capacity < 1)
		v->capacity = VECTOR_INIT_CAPACITY;
	else
		v->capacity = capacity;
	v->total = 0;
	v->size = data_size;
	v->del = del;
	v->ptr = malloc(data_size * v->capacity);
	if (!v->ptr)
		return (FAILURE);
	ft_memset(v->ptr, 0, data_size);
	return (SUCCESS);
}
