/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:58:16 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/09 12:02:18 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

#include <stdlib.h>

int	init_path(t_vector *envv)
{
	t_env_var	env_var;
	char		*path;

	path = ft_getenv(envv, "PATH");
	if (!path)
	{
		env_var.name = ft_strdup("PATH");
		if (!env_var.name)
			return (FAILURE);
		env_var.value = ft_strdup(__DEFAULT_PATH);
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
