/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/06 15:56:35 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"

# include <stdio.h>

int	init_env(t_vector *envv, char **env)
{
	size_t	i;
	char	*tmp;

	(void)envv;
	// ft_vector_init(envv, sizeof(t_env_var), 0);
	i = 0;
	while (env[i])
	{
		tmp = ft_strtok(env[i], "=");
		printf("name = %s\n", tmp);
		printf("env[%zu] = %s\n", i, env[i]);
		// ft_vector_add(envv, &(t_env_var){.name = env[i], .value = NULL});
		i++;
	}
	printf("\nenvv.size = %zu\n\n\n", envv->size);
	return (0);
}