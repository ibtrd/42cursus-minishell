/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:30:06 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "env.h"

int	builtin_env(t_executor *exec, char **argv)
{
	size_t		i;
	char		**var;

	(void)argv;
	i = 0;
	var = (char **)ft_vector_get(exec->env, i);
	while (var && *var)
	{
		if (printf("%s\n", *var) == -1)
			return (1);
		i++;
		var = (char **)ft_vector_get(exec->env, i);
	}
	return (0);
}
