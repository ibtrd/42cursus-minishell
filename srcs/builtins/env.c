/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:30:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 17:29:34 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>

int	builtin_env(t_vector *env)
{
	size_t		i;
	// t_env_var	*env_var;

	// env_var = ft_vector_get(env, 0);
	// if (!env_var)
	//	return (1);
	i = 0;
	while (i < env->total)
	{
		printf("%s\n", *(char **)ft_vector_get(env, i));
		i++;
	}
	return (0);
}
