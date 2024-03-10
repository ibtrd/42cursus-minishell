/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_envars_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:46:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/10 01:43:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "parsing.h"
#include "env.h"
#include "expander.h"

static int	replace_envars(char **ptr, char **mask, t_vector *env);
static int	add_envar(t_vector expanded[2], size_t *index, t_vector *env);
static int	get_envar_name(char *str, char **ptr);

int	envars_expansion(char **ptr, char **mask, t_vector *env)
{
	t_escape	interpreter;
	char		*str;
	size_t		i;

	str = *ptr;
	init_escape(&interpreter);
	i = 0;
	while (str[i])
	{
		set_escape_mode(&interpreter, str[i]);
		if (interpreter.mode != _SINGLE && str[i] == '$')
			return (replace_envars(ptr, mask, env));
		i++;
	}
	return (SUCCESS);
}

static int	replace_envars(char **ptr, char **mask, t_vector *env)
{
	t_vector	expanded[2];
	t_escape	interpreter;
	char		*c;
	size_t		i;

	if (init_expansion_vectors(expanded, *ptr, *mask))
		return (FAILURE);
	printf("total=%ld\n", expanded->total);
	init_escape(&interpreter);
	i = 0;
	c = ft_vector_get(expanded, i);
	while (c)
	{
		printf("index=%ld\n", i);
		set_escape_mode(&interpreter, *c);
		if (interpreter.mode != _SINGLE && *c == '$')
			add_envar(expanded, &i, env);
		else
			i++;
		printf("\tindex=%ld\n", i);
		c = ft_vector_get(expanded, i);
	}
	free(*ptr);
	*ptr = expanded->ptr;
	return (SUCCESS);
}

static int	add_envar(t_vector expanded[2], size_t *index, t_vector *env)
{
	t_env_var	var;
	char		*str;

	str = ft_vector_get(expanded, *index);
	if (get_envar_name(str + 1, &var.name))
		return (FAILURE);
	if (remove_var_names(expanded, *index, var.name))
		return (FAILURE);
	var.value = ft_getenv(env, var.name);
	free(var.name);
	if (!var.value)
	{
		(*index)++;
		return (SUCCESS);
	}
	return (insert_var_values(expanded, index, var.value));
}

static int	get_envar_name(char *str, char **ptr)
{
	char	*envar;
	size_t	i;

	envar = ft_strdup(str);
	*ptr = envar;
	if (!envar)
		return (FAILURE);
	i = 0;
	if (str[i++] == '?')
	{
		envar[i] = '\0';
		*ptr = envar;
		return (SUCCESS);
	}
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	envar[i] = '\0';
	return (SUCCESS);
}
