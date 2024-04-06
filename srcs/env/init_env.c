/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 17:49:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
