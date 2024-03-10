/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/11 00:27:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

# include <stdio.h>
#include <stdlib.h>
# include "builtins.h"

static int	create_env(t_vector *envv)
{
	// t_env_var	env_var;
	int			error;

	(void)envv;
	error = 0;
	// env_var.name = ft_strdup("PATH");
	// if (!env_var.name)
	// 	error = 1;
	// env_var.value = ft_strdup("/usr/bin:/bin:/usr/sbin:/sbin");
	// if (!env_var.value)
	// 	error = 1;
	// if (!error)
	// 	error = ft_vector_add(envv, &env_var);
	// if (error)
	// 	ft_vector_free(envv, &free_var);
	return (error);
}

static int	copy_var(t_env_var *env_var, char *var)
{
	char	*tmp;

	tmp = ft_strtok(var, "=");
	env_var->name = ft_strdup(tmp);
	if (!env_var->name)
		return (1);
	tmp = ft_strtok(NULL, "");
	env_var->value = ft_strdup(tmp);
	if (!env_var->value)
	{
		free(env_var->name);
		return (1);
	}
	return (0);
}

static int	copy_env(t_vector *envv, char **env)
{
	size_t		i;
	t_env_var	env_var;

	if (ft_vector_init(envv, (t_vinfos){sizeof(t_env_var), 0, free_var}))
		return (1);
	i = 0;
	while (env[i])
	{
		tmp = ft_strtok(env[i], "=");
		env_var.name = ft_strdup(tmp);
		tmp = ft_strtok(NULL, "");
		env_var.value = ft_strdup(tmp);
		ft_vector_add(envv, &env_var); //PROTECTION
		i++;
	}
	return (0);
}


int	init_env(t_vector *envv, char **env)
{
	int			error;

	if (ft_vector_init(envv, sizeof(t_env_var), 0))
		return (1);
	if (!env || !*env)
		error = create_env(envv);
	else
		error = copy_env(envv, env);
	if (error)
		ft_vector_free(envv, &free_var);
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
