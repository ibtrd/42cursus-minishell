/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:26:41 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/29 18:19:37 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"
#include <stdlib.h>

int	ft_vector_resize(t_vector *v, size_t capacity)
{
	void	*new;

	if (!v || capacity < v->total || !capacity)
		return (FAILURE);
	new = malloc(v->size * capacity);
	if (!new)
		return (FAILURE);
	ft_memcpy(new, v->ptr, v->size * v->total);
	free(v->ptr);
	v->ptr = new;
	v->capacity = capacity;
	return (SUCCESS);
}
