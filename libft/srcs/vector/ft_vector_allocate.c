/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:49:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 20:50:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"

int	ft_vector_allocate(t_vector **ptr, size_t data_size, size_t capacity)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	if (!new)
		return (FAILURE);
	if (ft_vector_init(new, data_size, capacity))
	{
		free(new);
		return (FAILURE);
	}
	*ptr = new;
	return (SUCCESS);
}
