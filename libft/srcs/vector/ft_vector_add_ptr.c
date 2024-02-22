/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/22 18:23:42 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_add_ptr(t_vector *v, void *item)
{
	int	status;

	if (!v)
		return (FAILURE);
	if (v->total == v->capacity - 1)
	{
		status = ft_vector_resize(v, v->capacity << 1);
		if (status != FAILURE)
		{
			*((char **)v->ptr + v->total) = item;
			v->total++;
		}
	}
	else
	{
		*((char **)v->ptr + v->total) = item;
		v->total++;
		status = SUCCESS;
	}
	return (status);
}
