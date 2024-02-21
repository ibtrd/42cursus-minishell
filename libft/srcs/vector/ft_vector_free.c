/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:07:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/20 15:18:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_free(t_vector *v)
{
	int	status;

	status = UNDEFINED;
	if (v)
	{
		free(v->ptr);
		v->ptr = NULL;
		status = SUCCESS;
	}
	return (status);
}
