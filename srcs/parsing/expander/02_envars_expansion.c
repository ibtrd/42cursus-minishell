/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_envars_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:46:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/14 17:43:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "interpreter.h"
#include "expander.h"
#include "env.h"
#include "mask.h"

#include <stdio.h> //remove

static int	search_envars(t_vector *arg, size_t *index, t_vector *env);
static char	*get_var_name(t_vector *arg, size_t index);
static int	var_not_found(t_vector *str, size_t *index, char *name);
static int	expand_var(t_vector *str, size_t index, char *name, char *value);

int	envars_expansion(t_vector *str, t_vector *env)
{
	t_mask	*mask;
	size_t	i;

	i = 0;
	while (i < str->total)
	{
		mask = ft_vector_get(str, i);
		if (mask->c == '$' && !(mask->m & (__SQUOTE_MASK | __ENVAR_MASK))
			&& search_envars(str, &i, env))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
	(void)env;
}

static int	search_envars(t_vector *arg, size_t *index, t_vector *env)
{
	char	*name;
	void	*ptr;

	ptr = ft_vector_get(arg, *index + 1);
	if (!ptr)
		return (SUCCESS);
	name = get_var_name(arg, *index);
	if (!name)
		return (FAILURE);
	ptr = ft_getenv(env, name);
	if (!ptr)
		return (var_not_found(arg, index, name));
	return (expand_var(arg, *index, name, (char *)ptr));
}

static int	var_not_found(t_vector *str, size_t *index, char *name)
{
	if (!ft_isalnum(*name) && *name != '_' )
	{
		(*index)++;
		free(name);
		return (SUCCESS);
	}
	if (ft_vector_deleten(str, *index, ft_strlen(name) + 1))
	{
		free(name);
		return (FAILURE);
	}
	free(name);
	return (SUCCESS);
}

static int	expand_var(t_vector *str, size_t index, char *name, char *value)
{
	t_mask	*insert;
	size_t	len;
	char	m;

	len = ft_strlen(value);
	m = ((t_mask *)ft_vector_get(str, index + 1))->m | __ENVAR_MASK;
	insert = str_to_mask(value, m);
	if (ft_vector_deleten(str, index, ft_strlen(name) + 1)
		|| ft_vector_insertn(str, insert, index, len))
	{
		free(insert);
		free(name);
		return (FAILURE);
	}
	free(insert);
	free(name);
	return (SUCCESS);
}

static char	*get_var_name(t_vector *arg, size_t index)
{
	t_mask			*mask;
	char			*name;
	int				i;

	name = malloc((arg->total - index) * sizeof(char));
	if (!name)
		return (NULL);
	i = 0;
	mask = ft_vector_get(arg, ++index);
	name[i++] = mask->c;
	if (ft_isalnum(mask->c) || mask->c == '_')
	{
		mask = ft_vector_get(arg, ++index);
		while (mask && (ft_isalnum(mask->c) || mask->c == '_')
			&& index < arg->total)
		{
			name[i++] = mask->c;
			mask = ft_vector_get(arg, ++index);
		}
	}
	name[i] = '\0';
	printf("\n\nVARNAME= %s|\n", name);
	return (name);
}
