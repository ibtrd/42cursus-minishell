/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 16:16:17 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

# include <stdio.h>
# include "builtins.h"

static int	make_env(t_vector *envv)
{
	t_env_var	env_var;
	int			error;

	error = 0;
	env_var.name = ft_strdup("PATH");
	if (!env_var.name)
		error = 1;
	env_var.value = ft_strdup("/usr/bin:/bin:/usr/sbin:/sbin");
	if (!env_var.value)
		error = 1;
	if (!error)
		error = ft_vector_add(envv, &env_var);
	if (error)
		ft_vector_free(envv, &free_var);
	return (error);
}

static int	copy_env(t_vector *envv, char **env)
{
	size_t		i;
	char		*tmp;
	t_env_var	env_var;
	int			error;

	error = 0;
	i = 0;
	while (!error && env[i])
	{
		tmp = ft_strtok(env[i], "=");
		env_var.name = ft_strdup(tmp);
		if (!env_var.name)
			error = 1;
		tmp = ft_strtok(NULL, "");
		env_var.value = ft_strdup(tmp);
		error = var_update(&env_var);
		if (!env_var.value)
			error = 1;
		if (!error)
			error = ft_vector_add(envv, &env_var);
		i++;
	}
	return (error);
}


int	init_env(t_vector *envv, char **env)
{
	size_t		i;
	char		*tmp;
	t_env_var	env_var;
	int			error;

	if (ft_vector_init(envv, sizeof(t_env_var), 0))
		return (1);
	if (!env || !*env)
		error = make_env(envv);
	else
		error = copy_env(envv, env);
	if (error)
		ft_vector_free(envv, &free_var);
	return (error);
}

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
