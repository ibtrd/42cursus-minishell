/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_quote_removal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:55:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/15 16:40:19 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"
#include "mask.h"

int	quote_removal(t_vector *str)
{
	t_mask	*mask;
	size_t	i;

	i = 0;
	while (i < str->total)
	{
		mask = ft_vector_get(str, i);
		if (ft_ischarset(mask->c, __QUOTES) && !mask->m)
		{
			if (ft_vector_delete(str, i))
				return (FAILURE);
		}
		else
			i++;
	}
	return (SUCCESS);
}
