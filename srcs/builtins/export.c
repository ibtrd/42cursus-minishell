/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:17:52 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 18:26:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "env.h"
#include "minishelldef.h"
#include "builtins.h"

static int	check_var_name(char *var)
{
	size_t	i;

	i = 0;
	if (!ft_isalpha(var[i]) && var[i] != '_')
	{
		ft_dprintf(STDERR_FILENO, __INVALID_IDENTIFIER, __MINISHELL, var);
		return (FAILURE);
	}
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
		{
			ft_dprintf(STDERR_FILENO, __INVALID_IDENTIFIER, __MINISHELL, var);
			return (FAILURE);
		}
		i++;
	}
	if (var[i] == '=')
		return (SUCCESS);
	return (-2);
}

int	builtin_export(t_executor *exec, char **argv)
{
	size_t		i;
	int			error;
	int			ret;

	if (!argv)
		return (FAILURE);
	ret = 0;
	i = -1;
	while (argv[++i])
	{
		error = check_var_name(argv[i]);
		ret |= -error;
		if (error)
			continue ;
		if (update_var(exec->env, argv[i]))
			return (FAILURE);
	}
	return (ret & -FAILURE);
}
