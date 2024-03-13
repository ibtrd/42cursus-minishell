/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_word_splitting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 05:10:14 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/13 07:32:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"
#include "ast.h"

#include "stdio.h" //REMOVE

void	debug_print_vector_mask(void *ptr, size_t index);

static int	search_words(t_vector *str, t_vector *mask, size_t *insert, t_vector *args, t_vector *masks);
static int	split_word(t_vector *split, t_vector *str, t_vector *mask, size_t *start);
// static int	split_vector(t_vector *dest, t_vector *src, size_t start, size_t end);
static int	merge_vectors(t_vector *srcs, t_vector *masks, t_vector *split, size_t *insert);

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
	merge_vectors(args, masks, split, insert);
	free(split->ptr);
	free((split + 1)->ptr);
	free(split);
	return (SUCCESS);
}

static int	split_word(t_vector *split, t_vector *str, t_vector *mask, size_t *start)
{
	size_t		end;
	t_vector	new;

	end = *start + 1;
	while (end < str->total && !is_separator(str, mask, end))
		end++;
	if (ft_vector_split(str, *start, end - *start, &new)
		|| ft_vector_add(&new, "\0")
		|| ft_vector_print(&new, ft_vprint_char, "SPLIT-new")
		|| ft_vector_add(split, &new)
		|| ft_vector_split(mask, *start, end - *start, &new)
		|| ft_vector_add(&new, "\0")
		|| ft_vector_print(&new, debug_print_vector_mask, "SPLIT-new(mask)")
		|| ft_vector_add(split + 1, &new))
		return (FAILURE);
	ft_vector_print(str, ft_vprint_char, "SPLIT-rest");
	ft_vector_print(mask, debug_print_vector_mask, "SPLIT-rest(mask)");
	*start = end;
	return (SUCCESS);
}

static	int	merge_vectors(t_vector *args, t_vector *masks, t_vector *split, size_t *insert)
{
	if (ft_vector_delete(args, *insert)
		|| ft_vector_insertn(args, split, *insert, split->total)
		|| ft_vector_delete(masks, *insert)
		|| ft_vector_insertn(masks, split + 1, *insert, (split + 1)->total))
		return (FAILURE);
	return (SUCCESS);
}
