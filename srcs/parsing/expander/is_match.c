/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:41:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/19 18:57:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "expander.h"
#include "libft.h"
#include "parsing.h"

static int	cmp_pattern(char *str, t_mask *pat, size_t si, size_t pi);
static int	is_wildcard(t_mask *mask, char wildcard);
static int	add_match(char *file, t_vector *matches);

int	is_match(char *str, t_mask *pat, t_vector *matches)
{
	if (*str == '.' && pat->c != '.')
		return (SUCCESS);
	if (cmp_pattern(str, pat, 0, 0) && add_match(str, matches))
		return (FAILURE);
	return (SUCCESS);
}

int	is_match_dir(char *str, t_mask *pat, t_vector *matches)
{
	char	*strdir;

	if (*str == '.' && pat->c != '.')
		return (SUCCESS);
	strdir = ft_strjoin(str, "/");
	if (!strdir)
		return (FAILURE);
	if (cmp_pattern(strdir, pat, 0, 0) && add_match(strdir, matches))
	{
		free(strdir);
		return (FAILURE);
	}
	free(strdir);
	return (SUCCESS);
}

static int	cmp_pattern(char *str, t_mask *pat, size_t si, size_t pi)
{
	if (!str[si] && !pat[pi].c)
		return (MATCH);
	if (pat[pi].c && ft_ischarset(pat[pi].c, __QUOTES))
		return (cmp_pattern(str, pat, si, pi + 1));
	if (pat[pi].c && is_wildcard(pat + pi, '*'))
	{
		if (cmp_pattern(str, pat, si, pi + 1))
			return (MATCH);
		if (str[si])
			return (cmp_pattern(str, pat, si + 1, pi));
	}
	if (str[si] && pat[pi].c
		&& (is_wildcard(pat + pi, '?') || str[si] == pat[pi].c))
		return (cmp_pattern(str, pat, si + 1, pi + 1));
	return (NO_MATCH);
}

static int	is_wildcard(t_mask *mask, char wildcard)
{
	return (mask->c == wildcard && !(mask->m & __DQUOTE_MASK & __SQUOTE_MASK));
}

static int	add_match(char *file, t_vector *matches)
{
	t_vector	match;
	t_mask		*mask;

	if (ft_vector_init(&match, (t_vinfos){sizeof(t_mask), 0, NULL}))
		return (FAILURE);
	mask = str_to_mask(file, __FILE_MASK);
	if (!mask)
	{
		ft_vector_free(&match);
		return (FAILURE);
	}
	if (ft_vector_join(&match, mask, ft_strlen(file))
		|| ft_vector_add(&match, "\0")
		|| ft_vector_add(matches, &match))
	{
		free(mask);
		ft_vector_free(&match);
		return (FAILURE);
	}
	free(mask);
	return (SUCCESS);
}
