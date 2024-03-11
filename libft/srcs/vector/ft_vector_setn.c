/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_setn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:07:51 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/11 22:57:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_setn(t_vector *v, size_t index, const void *item, size_t n)
{
	size_t	i;

	if (!v || index + n > v->total)
		return (FAILURE);
	i = 0;
	while (i < n)
	{
		ft_memcpy(v->ptr + (index + i) * v->size, item, v->size);
		i++;
	}
	return (SUCCESS);
}
