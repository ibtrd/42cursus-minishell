/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_filename_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:29:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/16 22:12:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "expander.h"

#include "stdio.h" //REMOVE

// static int	search_for_matches(t_vector *args, size_t *index);

int	filemame_expansion(t_vector *args, size_t *index)
{
	t_vector	*str;

	str = ft_vector_get(args, *index);
	if (!is_pattern(str))
		return (SUCCESS);
	printf("\twildcard detected!\n");
	return (SUCCESS);
	// return (search_for_matches(args, index));
}

// static int	search_for_matches(t_vector *args, size_t *index)
// {
// 	t_vector		matches;
// 	DIR				*wd;
// 	struct dirent	*entry;

// 	if (ft_vector_init(&matches, (t_vinfos){sizeof(t_vector), 0, ft_vvector_free}))
// 		return (FAILURE);
// 	wd = opendir(__WORKING_DIRECTORY);
// 	if (!wd)
// 		return (opendir_error(__WORKING_DIRECTORY));
// 	errno = 0;
// 	entry = readdir(wd);
// 	while (entry)
// 	{
// 		printf("entry= %s\n", entry->d_name);
// 		entry = readdir(wd);
// 	}
// 	if (errno)
// 	{
// 		ft_vector_free(&matches);
// 		return (FAILURE);
// 	}
// 	closedir(wd);
// 	ft_vector_free(&matches);
// 	(void)args;
// 	(void)index;
// 	return (SUCCESS);
// }

// int	match_string(char *entry, t_vector *str, size_t	index)
// {
// 	t_mask	*mask;

// 	mask = ft_vector_get(str, index);
// 	if (!mask && !entry)
// 		return (SUCCESS);
// 	if (mask->c == '*' && !mask->m)
// }

// int	match_wildcard(char *entry, t_vector *str, size_t index)
// {

// }
