/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_filename_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:29:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/17 02:55:31 by ibertran         ###   ########lyon.fr   */
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
static int	check_match(char *entry, t_mask *str, t_wildcard mode);
static int	is_match(char *entry, t_mask *str);

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
		if (is_match(entry->d_name, ((t_vector *)ft_vector_get(args, *index))->ptr) == MATCH)
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

static int	is_match(char *entry, t_mask *str)
{
	if (*entry == '.' && str->c != '.')
		return (FAILURE);
	return (check_match(entry, str, _INACTIVE));
}

static int	check_match(char *entry, t_mask *str, t_wildcard mode)
{
	if ((!mode && !str->c && !*entry) || (mode && !str->c))
		return (MATCH);
	if ((str->c == '*' && !str->m) || ft_ischarset(str->c, __QUOTES))
		return (check_match(entry, ++str, _ASTERISK));
	if (!mode)
	{
		if (str->c == *entry)
			return (check_match(++entry, ++str, _INACTIVE));
		return (FAILURE);
	}
	else
	{
		if (!*entry)
			return (FAILURE);
		if (str->c == *entry)
			return (check_match(++entry, ++str, _INACTIVE));
		if (str->c != *entry)
			return (check_match(++entry, str, _ASTERISK));
		return (FAILURE);
	}
}
