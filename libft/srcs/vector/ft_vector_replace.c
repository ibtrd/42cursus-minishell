/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:00:36 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 15:05:38 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_replace(t_vector *v, size_t index, void *new)
{
	if (!v || index >= v->total)
		return (FAILURE);
	if (v->del)
		v->del((void **)ft_vector_get(v, index));
	ft_memcpy(v->ptr + index * v->size, new, v->size);
	return (SUCCESS);
}
