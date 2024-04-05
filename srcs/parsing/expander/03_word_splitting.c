/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_word_splitting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 05:10:14 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/05 18:34:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "expander.h"
#include "minishelldef.h"

static int	search_words(t_vector *args, t_vector *str, size_t *index);
static int	split_word(t_vector *split, t_vector *str, size_t *start);

int	word_splitting(t_vector *args, size_t *index)
{
	t_vector	*str;

	str = ft_vector_get(args, *index);
	if (str->total == 1)
	{
		if (ft_vector_delete(args, *index))
			return (FAILURE);
		(*index)--;
		return (REMOVAL);
	}
	if (!is_splittable(str))
		return (SUCCESS);
	return (search_words(args, str, index));
}

static int	search_words(t_vector *args, t_vector *str, size_t *index)
{
	t_vector	split;
	size_t		start;

	if (ft_vector_init(&split,
			(t_vinfos){sizeof(t_vector), 4, &ft_vvector_free}))
		return (FAILURE);
	start = 0;
	while (start < str->total)
	{
		while (start < str->total && is_separator(ft_vector_get(str, start)))
			start++;
		if (start < str->total && split_word(&split, str, &start))
		{
			ft_vector_free(&split);
			return (FAILURE);
		}
	}
	if (ft_vector_delete(args, *index) || ft_vector_merge(args, *index, &split))
	{
		ft_vector_free(&split);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	split_word(t_vector *split, t_vector *str, size_t *start)
{
	t_vector	new;
	size_t		end;

	end = *start + 1;
	while (end < str->total && !is_separator(ft_vector_get(str, end)))
		end++;
	if (ft_vector_split(str, *start, end - *start, &new))
		return (FAILURE);
	if (ft_vector_add(split, &new))
	{
		ft_vector_free(&new);
		return (FAILURE);
	}
	return (SUCCESS);
}
