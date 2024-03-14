/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:16:41 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 15:25:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"
#include "mask.h"

#include <stdio.h>

int	is_separator(t_vector *str, t_vector *mask, size_t index)
{
	const char	c = *(char *)(ft_vector_get(str, index));
	const char	m = *(char *)(ft_vector_get(mask, index));

	if (ft_ischarset(c, __DEFAULT_IFS)
		&& (m & __ENVAR_MASK)
		&& !(m & __DQUOTE_MASK))
		return (1);
	return (0);
}

int	is_splittable(t_vector *str, t_vector *mask)
{
	size_t	i;

	i = 0;
	while (i < str->total)
	{
		if (is_separator(str, mask, i))
			return (1);
		i++;
	}
	return (0);
}

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
