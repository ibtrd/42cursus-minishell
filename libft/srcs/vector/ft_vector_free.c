/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:24:54 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 13:56:09 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

int	ft_vector_free(t_vector *v, void (*del)(void *))
{
	size_t	i;

	if (!v)
		return (FAILURE);
	if (del)
	{
		i = 0;
		while (i < v->total)
			del(*(void **)ft_vector_get(v, i++));
	}
	free(v->ptr);
	v->ptr = NULL;
	return (SUCCESS);
}
