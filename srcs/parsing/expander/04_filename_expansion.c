/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_filename_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:29:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/17 23:17:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"

#include "stdio.h" //REMOVE

static int	search_for_matches(t_vector *args, size_t *index);
// static int	check_match(char *entry, t_mask *str, t_wildcard mode);
static int	is_match(char *str, t_mask *pattern, int si, int pi);

int	filemame_expansion(t_vector *args, size_t *index)
{
	t_vector	*str;

	str = ft_vector_get(args, *index);
	if (!is_pattern(str))
		return (SUCCESS);
	printf("\twildcard detected!\n");
	return (search_for_matches(args, index));
}

static int	search_for_matches(t_vector *args, size_t *index)
{
	t_vector		matches;
	DIR				*wd;
	struct dirent	*entry;

	if (ft_vector_init(&matches, (t_vinfos){sizeof(t_vector), 0, ft_vvector_free}))
		return (FAILURE);
	wd = opendir(__WORKING_DIRECTORY);
	if (!wd)
		return (opendir_error(__WORKING_DIRECTORY));
	errno = 0;
	entry = readdir(wd);
	while (entry)
	{
		printf("entry= %s\n", entry->d_name);
		if (is_match(entry->d_name, ((t_vector *)ft_vector_get(args, *index))->ptr, 0, 0) == MATCH)
			printf ("\e[32mMATCH! %s\e[0m\n\n", entry->d_name);
		else
			printf ("\e[31mMeh... %s\e[0m\n\n", entry->d_name);
		entry = readdir(wd);
	}
	printf("\n");
	if (errno)
	{
		ft_vector_free(&matches);
		return (FAILURE);
	}
	closedir(wd);
	ft_vector_free(&matches);
	(void)args;
	(void)index;
	return (SUCCESS);
}

static int	is_wildcard(t_mask *mask, char wildcard);

static int	is_match(char *str, t_mask *pattern, int si, int pi)
{
	if (!str[si] && !pattern[pi].c)
		return (MATCH);
	if (ft_ischarset(pattern[pi].c, __QUOTES))
		return (is_match(str, pattern, si, pi + 1));
	if (pattern[pi].c && is_wildcard(pattern + pi, '*'))
		return (is_match(str, pattern, si, pi + 1)
			|| (str[si] && is_match(str, pattern, si + 1, pi)));
	if (str[si] && pattern[pi].c
		&& (str[si] == pattern[pi].c || is_wildcard(pattern + pi, '?')))
		return (is_match(str, pattern, si + 1, pi + 1));
	return (NO_MATCH);
}

static int	is_wildcard(t_mask *mask, char wildcard)
{
	if (wildcard == '*')
		return (mask->c == '*' && !mask->m);
	if (wildcard == '?')
		return (mask->c == '?' && !mask->m);
	return (FAILURE);
}
