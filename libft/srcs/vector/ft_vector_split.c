/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:39:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 02:25:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_split(t_vector *v, size_t index, size_t n, t_vector *ptr)
{
	t_vector	split;

	if (!v || index >= v->total || index + n > v->total || !ptr)
		return (FAILURE);
	if (!n)
		return (SUCCESS);
	if (ft_vector_init(&split, (t_vinfos){v->size, n, v->del}))
		return (FAILURE);
	if (ft_vector_join(&split, ft_vector_get(v, index), n)
		|| ft_vector_unlink(v, index, n))
	{
		ft_vector_free(&split);
		*ptr = split;
		return (FAILURE);
	}
	*ptr = split;
	return (SUCCESS);
}
