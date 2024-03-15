/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:30:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/15 15:49:17 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "executor.h"

#include <stdio.h>

int	builtin_env(t_executor *exec, char **argv)
{
	size_t		i;
	char		**var;

	(void)argv;
	i = 0;
	var = (char **)ft_vector_get(exec->env, i);
	while (var && *var)
	{
		printf("%s\n", *var);
		i++;
		var = (char **)ft_vector_get(exec->env, i);
	}
	return (0);
}
