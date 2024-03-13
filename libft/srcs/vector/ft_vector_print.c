/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 04:49:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 05:22:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_print(t_vector *v, void (*print)(void *, size_t))
{
	size_t	i;

	if (!v || !print)
		return (FAILURE);
	printf("----------------------------\nPrinting vector %p\n\n", v);
	i = 0;
	while (i < v->total)
	{
		print(ft_vector_get(v, i), i);
		i++;
	}
	printf("\n----------------------------\n\n");
	return (SUCCESS);
}
