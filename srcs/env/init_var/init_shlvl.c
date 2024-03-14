/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:17:51 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 12:18:20 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "minishelldef.h"
#include "env.h"
#include "libft.h"

#include <stdlib.h>

int	init_shlvl(t_vector *envv)
{
	t_env_var	env_var;
	char		*shlvl;

	shlvl = ft_getenv(envv, "SHLVL");
	if (!shlvl)
	{
		env_var.name = ft_strdup("SHLVL");
		if (!env_var.name)
			return (FAILURE);
		env_var.value = ft_strdup("1");
		if (!env_var.value)
		{
			free(env_var.name);
			return (FAILURE);
		}
		if (ft_vector_add(envv, &env_var))
		{
			free(env_var.name);
			free(env_var.value);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
