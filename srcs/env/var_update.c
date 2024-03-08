/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:16:35 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 19:34:25 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

#include <stdlib.h>

int	var_update(t_env_var *var)
{
	int		i;

	if (ft_strcmp(var->name, "SHLVL") == 0)
	{
		i = ft_atoi(var->value) + 1;
		if (i >= __MAX_SHLVL)
		{
			ft_dprintf(
				2, 
				"%s: warning: shell level (%d) too high, resetting to 1\n", 
				__MINISHELL, 
				i);
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
