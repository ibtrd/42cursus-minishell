/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:24:54 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/13 14:26:30 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_free(t_vector *v)
{
	size_t	i;

	if (!v)
		return (FAILURE);
	if (v->del)
	{
		i = 0;
		while (i < v->total)
			v->del((void **)ft_vector_get(v, i++));
	}
	free(v->ptr);
	ft_memset(v, '\0', sizeof(t_vector));
	return (SUCCESS);
}
