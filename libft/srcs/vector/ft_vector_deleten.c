/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_deleten.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:25:25 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 15:01:20 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_deleten(t_vector *v, size_t index, size_t n)
{
	size_t	i;

	if (!v || index >= v->total || index + n > v->total)
		return (FAILURE);
	if (v->del)
	{
		i = index;
		while (i < index + n)
		{
			v->del((void **)ft_vector_get(v, i));
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
