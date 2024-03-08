/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:21:50 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 14:26:28 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_getenv(t_vector *env, char *name)
{
	size_t		i;
	t_env_var	*env_var;

	if (!env)
		return (NULL);
	env_var = (t_env_var *)env->ptr;	// ft_vector_get(env, 0);
	if (!env_var || !name)
		return (NULL);
	i = 0;
	while (i < env->total)
	{
		if (!ft_strcmp(env_var[i].name, name))
			return (env_var[i].value);
		i++;
	}
	return (NULL);
}