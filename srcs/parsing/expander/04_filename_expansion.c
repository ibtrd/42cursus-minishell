/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_filename_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:29:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/18 04:03:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"

#include "stdio.h" //REMOVE

static int	scan_directory(DIR *dir, t_vector *pattern, t_vector *matches);
static int	search_for_matches(t_vector *pattern, t_vector *matches);
static int	add_match(char *file, t_vector *matches);

int	filemame_expansion(t_vector *args, size_t *index)
{
	t_vector	*str;
	t_vector	matches;

	str = ft_vector_get(args, *index);
	if (!is_pattern(str))
		return (SUCCESS);
	if (ft_vector_init(&matches,
			(t_vinfos){sizeof(t_vector), 0, ft_vvector_free}))
		return (FAILURE);
	if (search_for_matches(str, &matches)
		|| (matches.total && (ft_vector_delete(args, *index)
				|| ft_vector_merge(args, *index, &matches))))
	{
		ft_vector_free(&matches);
		return (FAILURE);
	}
	return (MATCH);
}

static int	search_for_matches(t_vector *pattern, t_vector *matches)
{
	DIR				*dir;

	dir = opendir(__WORKING_DIRECTORY);
	if (!dir)
		return (opendir_error(__WORKING_DIRECTORY));
	if (scan_directory(dir, pattern, matches))
		return (FAILURE);
	ft_vector_sort(matches, vsort_masks);
	return (SUCCESS);
}

static int	scan_directory(DIR *dir, t_vector *pattern, t_vector *matches)
{
	struct dirent	*entry;

	errno = 0;
	entry = readdir(dir);
	while (entry)
	{
		if (is_match(entry->d_name, pattern->ptr))
		{
			printf ("\e[32mMATCH! %s\e[0m\n\n", entry->d_name);
			if (add_match(entry->d_name, matches))
			{
				closedir(dir);
				return (FAILURE);
			}
		}
		else //REMOVE
			printf ("\e[31mMeh... %s\e[0m\n\n", entry->d_name); //REMOVE
		entry = readdir(dir);
	}
	closedir(dir);
	return (errno);
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
