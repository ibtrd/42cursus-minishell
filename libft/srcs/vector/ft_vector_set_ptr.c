/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:26:05 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/29 18:19:40 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_set_ptr(t_vector *v, size_t index, void *item)
{
	if (!v || index >= v->total)
		return (FAILURE);
	*((void **)v->ptr + index) = item;
	return (SUCCESS);
}
