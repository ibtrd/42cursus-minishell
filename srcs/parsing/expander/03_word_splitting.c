/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_word_splitting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 05:10:14 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 09:18:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"
#include "ast.h"

#include "stdio.h" //REMOVE

static int	search_words(t_vector *str, t_vector *mask, size_t *insert, t_vector *args, t_vector *masks);
static int	split_word(t_vector *split, t_vector *str, t_vector *mask, size_t *start);
static int	split_vector(t_vector *dest, t_vector *src, size_t start, size_t end);
static	int vector_merge(t_vector *dst, t_vector *src, size_t *insert);

int	word_splitting(t_vector *args, t_vector *masks, size_t *index)
{
	t_vector	*str;
	t_vector	*mask;

	str = ft_vector_get(args, *index);
	mask = ft_vector_get(masks, *index);
	if (!is_splittable(str, mask))
		return (SUCCESS);
	return (search_words(str, mask, index, args, masks));
}

static int	search_words(t_vector *str, t_vector *mask, size_t *insert, t_vector *args, t_vector *masks)
{
	t_vector	*split;
	size_t		start;

	if (ft_vector_alloc(&split, (t_vinfos){sizeof(t_vector), 4, &del_args}, 2))
		return (FAILURE);
	start = 0;
	while (start < str->total)
	{
		while (start < str->total && is_separator(str, mask, start))
			start++;
		if (start < str->total - 1 && split_word(split, str, mask, &start))
		{
			ft_vector_dealloc(&split, 2);
			return (FAILURE);
		}
		start++;
	}
	vector_merge(args, split, insert);
	vector_merge(masks, split + 1, insert);
	free(split->ptr);
	free((split + 1)->ptr);
	free(split);
	return (SUCCESS);
}

static int	split_word(t_vector *split, t_vector *str, t_vector *mask, size_t *start)
{
	size_t		end;

	end = *start + 1;
	while (end < str->total && !is_separator(str, mask, end))
		end++;
	if ((split_vector(split, str, *start, end)
			|| split_vector(split + 1, mask, *start, end)))
		return (FAILURE);
	*start = end;
	return (SUCCESS);
}

static int	split_vector(t_vector *dest, t_vector *src, size_t start, size_t end)
{
	t_vector	new;

	if (ft_vector_init(&new, (t_vinfos){sizeof(char), end - start + 1, NULL}))
		return (FAILURE);
	if (ft_vector_insertn(&new, ft_vector_get(src, start), 0, end - start)
		|| ft_vector_add(&new, "\0") || ft_vector_add(dest, &new))
	{
		ft_vector_free(&new);
		return (FAILURE);
	}
	return (SUCCESS);
}

static	int	vector_merge(t_vector *dst, t_vector *src, size_t *insert)
{
	if (ft_vector_delete(dst, *insert) || ft_vector_insertn(dst, src->ptr, *insert, src->total))
		return (FAILURE);
	return (SUCCESS);
}
