/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_deallocate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:59:18 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 14:55:48 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vector.h"

int	ft_vector_deallocate(t_vector **ptr)
{
	if (!ptr || !*ptr)
		return (FAILURE);
	ft_vector_free(*ptr);
	free(*ptr);
	*ptr = NULL;
	return (SUCCESS);
}
