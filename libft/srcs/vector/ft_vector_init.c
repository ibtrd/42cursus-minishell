/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:50:49 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 16:07:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"
#include <stdlib.h>

int	ft_vector_init(t_vector *v, t_vinfos infos)
{
	if (!v || infos.data_size < 1)
		return (FAILURE);
	if (infos.capacity < 1)
		v->capacity = VECTOR_INIT_CAPACITY;
	else
		v->capacity = infos.capacity;
	v->total = 0;
	v->size = infos.data_size;
	v->del = infos.del;
	v->ptr = malloc(v->size * v->capacity);
	if (!v->ptr)
		return (FAILURE);
	ft_memset(v->ptr, 0, v->size); //REMOVE ?
	return (SUCCESS);
}
