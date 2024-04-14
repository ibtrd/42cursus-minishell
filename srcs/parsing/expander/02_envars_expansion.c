/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_envars_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:46:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/14 20:45:21 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "expander.h"
#include "env.h"

static int	search_envars(t_vector *str, size_t index, t_minishell *env);
static char	*get_var_name(t_vector *arg, size_t index);
static int	expand_var(t_vector *str, size_t index, char *name, char *value);
static int	var_not_found(t_vector *str, size_t index, char *name);

int	envars_expansion(t_vector *str, t_minishell *env)
{
	t_mask	*mask;
	size_t	i;

	i = 0;
	while (i < str->total)
	{
		mask = ft_vector_get(str, i);
		ft_dprintf(2, "%c ", mask->c);
		if (mask->c == '$' && !(mask->m & (__SQUOTE_MASK | __ENVAR_MASK)))
		{
			if (search_envars(str, i, env))
				return (FAILURE);
		}
		else
			i++;
	}
	return (SUCCESS);
}

static int	search_envars(t_vector *str, size_t index, t_minishell *env)
{
	char	*name;
	char	*value;
	t_mask	*mask;

	mask = ft_vector_get(str, index + 1);
	if (!mask)
		return (SUCCESS);
	if ((!ft_isalpha(mask->c) && mask->c != '_'))
		return (is_special_param(str, index, mask->c, env));
	name = get_var_name(str, index);
	if (!name)
		return (FAILURE);
	value = ft_getenv(&env->env, name);
	if (!value)
		return (var_not_found(str, index, name));
	return (expand_var(str, index, name, value));
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
	while (mask && (ft_isalnum(mask->c) || mask->c == '_')
		&& index < arg->total)
	{
		name[i++] = mask->c;
		mask = ft_vector_get(arg, ++index);
	}
	name[i] = '\0';
	return (name);
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

static int	var_not_found(t_vector *str, size_t index, char *name)
{
	if (ft_vector_deleten(str, index, ft_strlen(name) + 1))
	{
		free(name);
		return (FAILURE);
	}
	free(name);
	return (SUCCESS);
}
