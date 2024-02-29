/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:01:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/29 18:19:51 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_trim(t_vector *v)
{
	void	*new;

	if (!v)
		return (FAILURE);
	if (v->total == v->capacity)
		return (SUCCESS);
	new = malloc(v->size * v->total);
	if (!new)
		return (FAILURE);
	ft_memcpy(new, v->ptr, v->size * v->total);
	free(v->ptr);
	v->ptr = new;
	v->capacity = v->total;
	return (SUCCESS);
}
