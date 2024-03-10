/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/10 19:41:37 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

# include <stdio.h>
# include "builtins.h"

int	init_env(t_vector *envv, char **env)
{
	size_t		i;
	char		*tmp;
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
