/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_strncat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:33 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/29 18:41:43 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_strncat(t_vector *v, char *str, size_t len)
{
	if (!v)
		return (FAILURE);
	if (!len)
		return (SUCCESS);
	if (v->total > 0 && *(char *)ft_vector_get(v, v->total - 1) == '\0')
		v->total--;
	while (v->total + len + 1 > v->capacity)
	{
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	}
	ft_memcpy(v->ptr + v->size * v->total, str, v->size * len);
	*((char *)v->ptr + v->size * (v->total + len)) = '\0';
	v->total += len + 1;
	return (SUCCESS);
}
