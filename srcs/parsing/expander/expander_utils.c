/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:16:41 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/19 19:01:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "libft.h"
#include "parsing.h"

int	is_expandable(t_vector *arg, char *interpreters)
{
	size_t	i;

	i = 0;
	while (i < arg->total)
	{
		if (ft_ischarset(((t_mask *)ft_vector_get(arg, i))->c, interpreters))
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

int	is_pattern(t_vector *str)
{
	t_mask	*mask;
	size_t	i;

	i = 0;
	while (i < str->total)
	{
		mask = ft_vector_get(str, i);
		if ((mask->c == '*' || mask->c == '?')
			&& !(mask->m & __DQUOTE_MASK & __SQUOTE_MASK))
			return (1);
		i++;
	}
	return (0);
}
