/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:16:35 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 19:20:19 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"

int	var_update(t_vector *env,t_env_var *var)
{
	char	*tmp;
	int		i;

	if (ft_strcmp(var->name, "SHLVL") == 0)
	{
		tmp = var->value;
		i = ft_atoi(tmp) + 1;
		if (i >= __MAX_SHLVL)
		{
			ft_dprintf(
				2, 
				"%s: warning: shell level (%d) too high, resetting to 1\n", 
				__MINISHELL, 
				i);
			i = 1;
		}
		var->value = ft_itoa(i);
		free(tmp);
		if (!var->value)
			return (FAILURE);
	}
	return (SUCCESS);
}
