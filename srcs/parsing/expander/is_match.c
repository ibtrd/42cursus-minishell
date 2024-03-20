/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_pattern.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:31:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/18 00:48:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minishelldef.h"
#include "mask.h"

static int	cmp_pattern(char *str, t_mask *pat, size_t si, size_t pi);
static int	is_wildcard(t_mask *mask, char wildcard);

int	is_match(char *str, t_mask *pat)
{
	if (*str == '.' && pat->c != '.')
		return (NO_MATCH);
	return (cmp_pattern(str, pat, 0, 0));
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
	return (mask->c == wildcard && !mask->m);
}
