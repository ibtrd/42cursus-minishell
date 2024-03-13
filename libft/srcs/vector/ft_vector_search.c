/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:38:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 04:12:41 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

void	*ft_vector_search(t_vector *v, const void *item)
{
	void	*ptr;
	size_t	index;

	if (!v)
		return (NULL);
	index = 0;
	while (index < v->total)
	{
		ptr = v->ptr + index * v->size;
		if (!ft_memcmp(ptr, item, v->size))
			return (ptr);
		index++;
	}
	return (NULL);
}
