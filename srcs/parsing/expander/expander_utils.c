/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:16:41 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/15 03:25:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"
#include "mask.h"

int	is_expandable(t_vector *arg)
{
	size_t	i;

	i = 0;
	while (i < arg->total)
	{
		if (ft_ischarset(((t_mask *)ft_vector_get(arg, i))->c, __INTERPRETERS))
			return (1);
		i++;
	}
	return (0);
}

int	is_separator(t_mask *mask)
{
	if (ft_ischarset(mask->c, __DEFAULT_IFS)
		&& mask->m & __ENVAR_MASK
		&& !(mask->m & __DQUOTE_MASK))
		return (1);
	return (0);
}

int	is_splittable(t_vector *str)
{
	size_t	i;

	i = 0;
	while (i < str->total)
	{
		if (is_separator(ft_vector_get(str, i)))
			return (1);
		i++;
	}
	return (0);
}

