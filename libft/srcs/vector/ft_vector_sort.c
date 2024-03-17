/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:58:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/17 04:33:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_sort(t_vector *v, int (*cmp)(void *, void *))
{
	size_t	i;
	void	*tmp;

	if (!v || !cmp)
		return (FAILURE);
	tmp = malloc(v->size);
	if (!tmp)
		return (FAILURE);
	i = 0;
	while (i < v->total - 1)
	{
		if (cmp(ft_vector_get(v, i), ft_vector_get(v, i + 1)))
		{
			ft_memcpy(tmp, v->ptr + i * v->size, v->size);
			ft_memcpy(v->ptr + i * v->size, v->ptr + (i + 1) * v->size, v->size);
			ft_memcpy(v->ptr + (i + 1) * v->size, tmp, v->size);
			i = 0;
		}
		else
			i++;
	}
	free(tmp);
	return (SUCCESS);
}
