/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:26:23 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/05 23:34:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	ft_vector_add_ptr(t_vector *v, void *item)
{
	if (!v)
		return (FAILURE);
	if (v->total == v->capacity)
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	*((void **)v->ptr + v->total) = item;
	v->total++;
	return (SUCCESS);
}
