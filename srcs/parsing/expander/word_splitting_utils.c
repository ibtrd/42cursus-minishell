/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:16:41 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 08:45:41 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"

#include <stdio.h>

int	is_separator(t_vector *str, t_vector *mask, size_t index)
{
	const char	c = *(char *)(ft_vector_get(str, index));
	const char	m = *(char *)(ft_vector_get(mask, index));

	printf("c=%c\n",c);
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
