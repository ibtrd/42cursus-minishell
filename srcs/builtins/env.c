/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:30:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 16:31:49 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "executor.h"

#include <stdio.h>

int	builtin_env(t_executor *exec, char **argv)
{
	size_t		i;

	(void)argv;
	i = 0;
	while (i < exec->env->total)
	{
		printf("%s\n", *(char **)ft_vector_get(exec->env, i));
		i++;
	}
	return (0);
}
