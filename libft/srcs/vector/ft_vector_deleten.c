/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_deleten.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:25:25 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 18:05:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"
#include <stddef.h>

int	ft_vector_deleten(t_vector *v, size_t index, size_t n, void (*del)(void **))
{
	size_t	i;

	if (!v || index >= v->total || index + n > v->total)
		return (FAILURE);
	if (del)
	{
		i = index;
		while (i < index + n)
		{
			del((void **)ft_vector_get(v, i));
			i++;
		}
	}
	ft_memcpy(v->ptr + index * v->size, v->ptr + (index + n) * v->size,
		(v->total - n - index) * v->size);
	v->total -= n;
	if (v->total > 0 && v->total == (v->capacity >> 2))
		return (ft_vector_resize(v, v->capacity >> 1));
	return (SUCCESS);
}
