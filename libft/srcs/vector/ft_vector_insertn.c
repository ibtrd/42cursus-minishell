/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insertn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 18:41:01 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_insertn(t_vector *v, void *item, size_t index, size_t n)
{
	if (!v || index > v->total)
		return (FAILURE);
	if (!n)
		return (SUCCESS);
	while (v->total + n > v->capacity)
	{
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	}
	ft_memmove(v->ptr + v->size * (index + n), v->ptr + v->size * index,
		v->size * (v->total - index));
	ft_memcpy(v->ptr + v->size * index, item, v->size * n);
	v->total += n;
	return (SUCCESS);
}
