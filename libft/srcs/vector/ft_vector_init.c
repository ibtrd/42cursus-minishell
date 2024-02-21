/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:38:32 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/18 22:14:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_init(t_vector *v, size_t size)
{
	if (!v)
		return (FAILURE);
	v->ptr = malloc(size * VECTOR_INIT_CAPACITY);
	if (!v->ptr)
		return (FAILURE);
	ft_memset(v->ptr, '\0', size);
	v->size = size;
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	return (SUCCESS);
}
