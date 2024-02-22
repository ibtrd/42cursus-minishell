/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert_ptr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 18:23:44 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_insert_ptr(t_vector *v, void *item, size_t index)
{
	int	status;

	if (!v)
		return (FAILURE);
	if (v->total == v->capacity - 1)
	{
		status = ft_vector_resize(v, v->capacity << 1);
		if (status != FAILURE)
		{
			ft_memmove(v->ptr + v->size * (index + 1), v->ptr + v->size * index,
				v->size * (v->total - index));
			*((char **)v->ptr + index) = item;
			v->total++;
		}
	}
	else
	{
		ft_memmove(v->ptr + v->size * (index + 1), v->ptr + v->size * index,
			v->size * (v->total - index));
		*((char **)v->ptr + index) = item;
		v->total++;
		status = SUCCESS;
	}
	return (status);
}
