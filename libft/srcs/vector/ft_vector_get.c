/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:25:48 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/13 03:44:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vector_get(t_vector *v, size_t index)
{
	void	*ptr;

	if (!v || index >= v->total)
		return (NULL);
	ptr = v->ptr + index * v->size;
	return (ptr);
}
