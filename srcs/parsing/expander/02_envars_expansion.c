/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_envars_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:46:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 02:15:28 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "minishelldef.h"
#include "interpreter.h"
#include "env.h"

#include <stdio.h> //remove

static int	search_envars(t_vector *arg, t_vector *mask, t_vector *env);
static int replace_envar(t_vector *arg, t_vector *mask, t_env_var envar, size_t *index);
static char	*get_envar_name(const char *str);

int	envars_expansion(t_vector *args, t_vector *masks, size_t index, t_vector *env)
{
	t_vector	*str;
	t_vector	*mask;

	str = ft_vector_get(args, index);
	mask = ft_vector_get(masks, index);
	if (ft_strchr((char *)str->ptr, '$'))
		return (search_envars(str, mask, env));
	return (SUCCESS);
}

static int	search_envars(t_vector *arg, t_vector *mask, t_vector *env)
{
	t_escape	interpreter;
	char		*str;
	size_t		i;
	t_env_var	envar;

	init_escape(&interpreter);
	i = 0;
	while (i < arg->total)
	{
		str = ft_vector_get(arg, 0);
		set_escape_mode(&interpreter, str[i]);
		if (interpreter.mode != _SINGLE && str[i] == '$')
		{
			envar.name = get_envar_name(str + i + 1);
			if (!envar.name)
				return (FAILURE);
			envar.value = ft_getenv(env, envar.name);
			if (replace_envar(arg, mask, envar, &i))
				return (FAILURE);
		}
		else
			i++;
	}
	return (SUCCESS);
}

static int	replace_envar(t_vector *arg, t_vector *mask, t_env_var envar, size_t *index)
{
	const char	m = *((char *)ft_vector_get(mask, *index)) | __ENVAR_MASK;
	size_t		name_len;
	size_t		value_len;

	if (!envar.value)
	{
		if (!*envar.name)
			envar.value = "$";
		else
			envar.value = "";
	}
	name_len = ft_strlen(envar.name) + 1;
	value_len = ft_strlen(envar.value);
	if (ft_vector_deleten(arg, *index, name_len)
		|| ft_vector_insertn(arg, envar.value, *index, value_len)
		|| ft_vector_deleten(mask, *index, name_len)
		|| ft_vector_insertn(mask, envar.value, *index, value_len)
		|| ft_vector_setn(mask, *index, &m, value_len))
	{
		free(envar.name);
		return (FAILURE);
	}
	free(envar.name);
	*index += value_len;
	return (SUCCESS);
}

static char	*get_envar_name(const char *str)
{
	const size_t	len = ft_strlen(str);
	char			*name;
	size_t			i;

	name = ft_calloc((len + 1), sizeof(char));
	if (!name)
		return (NULL);
	i = 0;
	name[i] = str[i];
	while (ft_isalnum(str[i]) || str[i] == '_')
	{
		name[i] = str[i];
		i++;
	}
	if (i == 0 && name[i] != '?')
		name[i] = '\0';
	return (name);
}
