/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:49:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 18:35:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"

int	ft_vector_alloc(t_vector **ptr, t_vinfos infos, size_t n)
{
	t_vector	*new;
	size_t		i;

	new = malloc(sizeof(t_vector) * n);
	if (!new)
		return (FAILURE);
	i = 0;
	while (i < n)
	{
		if (ft_vector_init(new + i, infos))
		{
			while (i--)
				ft_vector_free(new + i);
			free(new);
			return (FAILURE);
		}
		i++;
	}
	*ptr = new;
	return (SUCCESS);
}