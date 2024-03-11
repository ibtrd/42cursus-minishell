/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_envars_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:46:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/11 00:59:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>

// #include "libft.h"

// #include "minishelldef.h"
// #include "parsing.h"
// #include "env.h"
// #include "expander.h"

// static int	replace_envars(char **ptr, char **mask, t_vector *env);
// static int	add_envar(t_vector expanded[2], size_t *index, t_vector *env);
// static int	get_envar_name(char *str, char **ptr);

// int	envars_expansion(char **ptr, char **mask, t_vector *env)
// {
// 	t_escape	interpreter;
// 	char		*str;
// 	size_t		i;

// 	str = *ptr;
// 	init_escape(&interpreter);
// 	i = 0;
// 	while (str[i])
// 	{
// 		set_escape_mode(&interpreter, str[i]);
// 		if (interpreter.mode != _SINGLE && str[i] == '$')
// 			return (replace_envars(ptr, mask, env));
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// static int	replace_envars(char **ptr, char **mask, t_vector *env)
// {
// 	t_vector	expanded[2];
// 	char		*c;
// 	char		*m;
// 	size_t		i;

// 	if (init_expansion_vectors(expanded, *ptr, *mask))
// 		return (FAILURE);
// 	i = 0;
// 	c = ft_vector_get(expanded, i);
// 	m = ft_vector_get(expanded + 1, i);
// 	while (c)
// 	{
// 		if (!ft_ischarset(*m, __ENVARS_ESCAPE) && *c == '$')
// 			add_envar(expanded, &i, env);
// 		else
// 			i++;
// 		c = ft_vector_get(expanded, i);
// 		m = ft_vector_get(expanded + 1, i);
// 	}
// 	return (replace_vector_pointers(ptr, mask, expanded));
// }

// static int	add_envar(t_vector expanded[2], size_t *index, t_vector *env)
// {
// 	t_env_var	var;
// 	char		*str;

// 	str = ft_vector_get(expanded, *index);
// 	if (get_envar_name(str + 1, &var.name))
// 		return (FAILURE);
// 	if (remove_var_names(expanded, *index, var.name))
// 		return (FAILURE);
// 	var.value = ft_getenv(env, var.name);
// 	if (!var.value && !*var.name)
// 		var.value = "$";
// 	free(var.name);
// 	if (!var.value)
// 	{
// 		(*index)++;
// 		return (SUCCESS);
// 	}
// 	return (insert_var_values(expanded, index, var.value));
// }

// static int	get_envar_name(char *str, char **ptr)
// {
// 	char			*envar;
// 	const size_t	len = ft_strlen(str);
// 	size_t			i;

// 	envar = ft_calloc((len + 2), sizeof(char));
// 	*ptr = envar;
// 	if (!envar)
// 		return (FAILURE);
// 	i = 0;
// 	envar[i] = str[i];
// 	while (ft_isalnum(str[i]) || str[i] == '_')
// 	{
// 		envar[i] = str[i];
// 		i++;
// 	}
// 	if (i == 0 && envar[i] != '?')
// 		envar[i] = '\0';
// 	return (SUCCESS);
// }
