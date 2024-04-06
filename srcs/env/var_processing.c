/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:16:35 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 17:51:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "minishelldef.h"
#include "env.h"

int	var_processing(t_env_var *var)
{
	int		i;

	if (ft_strcmp(var->name, "SHLVL") == 0)
	{
		i = ft_atoi(var->value) + 1;
		if (i >= __MAX_SHLVL)
		{
			ft_dprintf(STDERR_FILENO, __HIGH_SHLVL, __MINISHELL, i);
			i = 1;
		}
		free(var->value);
		var->value = ft_itoa(i);
		if (!var->value)
		{
			free(var->name);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
