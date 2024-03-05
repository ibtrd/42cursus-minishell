/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_deallocate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:59:18 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/05 21:10:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"

int	ft_vector_deallocate(t_vector **ptr, void (*del)(void *))
{
	if (!ptr || !*ptr)
		return (FAILURE);
	ft_vector_free(*ptr, del);
	free(*ptr);
	*ptr = NULL;
	return (SUCCESS);
}
