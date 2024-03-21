/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/21 18:48:49 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

# include <stdio.h>
#include <stdlib.h>
# include "builtins.h"

static int	create_env(t_vector *env)
{
	if (ft_vector_add_ptr(env, NULL))
		return (FAILURE);
	if (init_path(env))
		return (FAILURE);
	if (init_shlvl(env))
		return (FAILURE);
	return (SUCCESS);
}

static int	copy_env(t_vector *env, char **old_env)
{
	size_t		i;

	i = 0;
	if (ft_vector_add_ptr(env, NULL))
		return (FAILURE);
	while (old_env[i])
	{
		if (add_var(env, old_env[i]))
			return (FAILURE);
		i++;
	}
	if (init_shlvl(env))
		return (FAILURE);
	return (SUCCESS);
}

int	init_env(t_vector *env, char **old_env)
{
	int			error;

	if (ft_vector_init(env, (t_vinfos){sizeof(char *), 0, &ft_vfree}))
		return (1);
	if (!old_env || !*old_env)
		error = create_env(env);
	else
		error = copy_env(env, old_env);
	if (error)
		ft_vector_free(env);
	return (error);
}

// Default PATH is /usr/bin:/bin:/usr/sbin:/sbin
///usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

// int	init_env(t_vector *envv, char **env)
// {
// 	size_t		i;
// 	char		*tmp;
// 	t_env_var	env_var;
// 	int			error;

// 	if (ft_vector_init(envv, sizeof(t_env_var), 0))
// 		return (1);
// 	error = 0;
// 	i = 0;
// 	while (env[i])
// 	{
// 		tmp = ft_strtok(env[i], "=");
// 		env_var.name = ft_strdup(tmp);
// 		if (!env_var.name)
// 			error = 1;
// 		tmp = ft_strtok(NULL, "");
// 		env_var.value = ft_strdup(tmp);
// 		if (!env_var.value)
// 			error = 1;
// 		if (error)
// 		{
// 			ft_vector_free(envv, &free_var);
// 			return (1);
// 		}
// 		if (ft_vector_add(envv, &env_var))
// 		{
// 			ft_vector_free(envv, &free_var);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
