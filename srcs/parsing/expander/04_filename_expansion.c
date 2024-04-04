/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_filename_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:29:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/04 14:22:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "libft.h"
#include "expander.h"

#include "minishelldef.h"

static int	scan_directory(DIR *dir, t_vector *pattern, t_vector *matches);
static int	search_for_matches(t_vector *pattern, t_vector *matches);

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
	{
		closedir(dir);
		return (FAILURE);
	}
	closedir(dir);
	ft_vector_sort(matches, vsort_masks);
	return (SUCCESS);
}

static int	scan_directory(DIR *dir, t_vector *pattern, t_vector *matches)
{
	struct dirent	*entry;

	errno = 0;
	entry = readdir(dir);
	while (!errno && entry)
	{
		if (*(char *)(ft_vector_get(pattern, pattern->total - 2)) == '/'
			&& entry->d_type == DT_DIR
			&& is_match_dir(entry->d_name, pattern->ptr, matches))
			return (FAILURE);
		if (is_match(entry->d_name, pattern->ptr, matches))
			return (FAILURE);
		entry = readdir(dir);
	}
	return (errno);
}
