/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:23:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 11:35:16 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_copy(t_vector *v, size_t index, void **ptr)
{
	if (!v || index >= v->total)
		return (FAILURE);
	ft_memcpy(*ptr, v->ptr + (index * v->size), v->size);
	return (SUCCESS);
}
