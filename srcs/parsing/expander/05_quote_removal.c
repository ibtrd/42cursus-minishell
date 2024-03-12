/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_quote_removal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:55:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 03:23:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"

#include <stdio.h> //REMOVE

int	quote_removal(t_vector *args, t_vector *masks, size_t *index)
{
	t_vector	*str;
	t_vector	*mask;
	size_t		i;

	str = ft_vector_get(args, *index);
	mask = ft_vector_get(masks, *index);
	i = 0;
	while (i < str->total)
	{
		if (!ft_ischarset(*(char *)(ft_vector_get(str, i)), "\"\'")
			|| *(char *)(ft_vector_get(mask, i)) | __NO_MASK)
		{
			i++;
		}
		else if (ft_vector_delete(str, i) || ft_vector_delete(mask, i))
			return (FAILURE);
	}
	return (SUCCESS);
}
