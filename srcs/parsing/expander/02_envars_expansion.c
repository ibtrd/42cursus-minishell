/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_envars_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:46:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/09 17:52:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "parsing.h"
#include "env.h"

static int	replace_envars(char **ptr, t_vector *env);
static int	add_envar(t_vector *expanded, char *str, size_t *index, t_vector *env);
static char	*get_envar_name(char *str);

int	envars_expansion(char **ptr, t_vector *env)
{
	t_escape	quote;
	char		*str;
	size_t		i;

	str = *ptr;
	init_escape(&quote);
	i = 0;
	while (str[i])
	{
		set_escape_mode(&quote, str[i]);
		if (quote.mode != _SINGLE && str[i] == '$')
			return (replace_envars(ptr, env));
		i++;
	}
	return (SUCCESS);
}

static int	replace_envars(char **ptr, t_vector *env)
{
	t_vector	expanded;
	t_escape	quote;
	char		*str;
	size_t		i;

	if (ft_vector_init(&expanded, sizeof(char), 0))
		return (FAILURE);
	str = *ptr;
	init_escape(&quote);
	i = 0;
	while (str[i])
	{
		set_escape_mode(&quote, str[i]);
		if (quote.mode != _SINGLE && str[i] == '$')
			add_envar(&expanded, str, &i, env);
		else
			ft_vector_add(&expanded, str + i++);
	}
	ft_vector_add(&expanded, "\0");
	free(*ptr);
	*ptr = expanded.ptr;
	return (SUCCESS);
}

static int	add_envar(t_vector *expanded, char *str, size_t *index, t_vector *env)
{
	t_env_var	var;

	(*index)++;
	var.name = get_envar_name(str + *index);
	if (!var.name)
		return (FAILURE);
	var.value = ft_getenv(env, var.name);
	*index += ft_strlen(var.name);
	free(var.name);
	if (!var.value)
		return (SUCCESS);
	return (ft_vector_join(expanded, var.value, ft_strlen(var.value)));
}

static char	*get_envar_name(char *str)
{
	char	*envar;
	size_t	i;

	envar = ft_strdup(str);
	if (!envar)
		return (NULL);
	i = 1;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	envar[i] = '\0';
	return (envar);
}
