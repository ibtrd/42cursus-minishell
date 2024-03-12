/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:01:41 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:30:41 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

int	add_var(t_vector *envv, char *var)
{
	char	*env_var;

	env_var = NULL;
	env_var = ft_strdup(var);
	if (!env_var || ft_vector_add_ptr(envv, env_var))
		return (FAILURE);
	return (SUCCESS);
}

// int	add_var(t_vector *envv, char *var)
// {
// 	t_env_var	env_var;

// 	env_var = (t_env_var){0};
// 	if (copy_var(&env_var, var))
// 		return (FAILURE);
// 	if (var_processing(&env_var))
// 		return (FAILURE);
// 	if (ft_vector_add(envv, &env_var))
// 		return (FAILURE);
// 	return (SUCCESS);
// }
