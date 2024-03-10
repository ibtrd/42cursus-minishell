/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_replacen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:00:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 15:51:57 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_replacen(t_vector *v, size_t index, void *new, size_t n[2])
{
	size_t	i;

	if (!v || index >= v->total || index + n[0] > v->total)
		return (FAILURE);
	while (v->total - n[0] + n[1] > v->capacity)
	{
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	}
	if (v->del)
	{
		i = 0;
		while (i < n[0])
		{
			v->del((void **)ft_vector_get(v, index + i));
			i++;
		}
	}
	ft_memcpy(v->ptr + index * v->size, new, n[0] * v->size);
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
