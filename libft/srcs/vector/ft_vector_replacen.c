/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_replacen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:00:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 18:54:02 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

# include <stdio.h>

int	ft_vector_replacen(t_vector *v, size_t index, void *new, size_t n[2])
{
	size_t	i;

	// printf("capacity = %zu\n", v->capacity);
	// printf("total = %zu\n", v->total);
	// printf("index = %zu\n", index);
	// printf("n[0] = %zu\n", n[0]);
	// printf("n[1] = %zu\n", n[1]);
	// printf("index + n[0] = %zu\n", index + n[0]);
	if (!v || index >= v->total || index + n[0] > v->total)
		return (FAILURE);
	// printf("v-total - n[0] + n[1] = %zu\n", v->total - n[0] + n[1]);
	while (v->total - n[0] + n[1] > v->capacity)
	{
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	}
	// printf("capacity = %zu\n", v->capacity);
	if (v->del)
	{
		i = 0;
		while (i < n[0])
		{
			v->del((void **)ft_vector_get(v, index + i));
			i++;
		}
	}
	// printf("first memcpy\n");
	// printf("(index + n[1]) * v->size = %zu\n", (index + n[1]) * v->size);
	// printf("(index + n[0]) * v->size = %zu\n", (index + n[0]) * v->size);
	// printf("v->total - (index + n[0]) * v->size = %zu\n", v->total - (index + n[0]) * v->size);
	ft_memmove(v->ptr + (index + n[1]) * v->size,
		v->ptr + (index + n[0]) * v->size,
		(v->total - (index + n[0])) * v->size);
	// printf("second memcpy\n");
	ft_memcpy(v->ptr + index * v->size, new, n[1] * v->size);
	v->total = v->total - n[0] + n[1];
	while (v->capacity > 1 && v->total <= (v->capacity >> 2))
		if (ft_vector_resize(v, v->capacity >> 1))
			return (FAILURE);
	return (SUCCESS);
}


/*


total
index
n[0]
n[1]



total = 10
index = 3
n[0] = 2
n[1] = 3

index + n[0] = 5
total - (index + n[0]) = 5

total - n[0] = 8

total - n[0] + n[1] = 11


*/
