/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_copyn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:23:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 13:36:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_copyn(t_vector *v, size_t index, size_t n, void *ptr)
{
	if (!v || index >= v->total || index + n > v->total || !ptr)
		return (FAILURE);
	ft_memcpy(ptr, v->ptr + (index * v->size), v->size * n);
	return (SUCCESS);
}
