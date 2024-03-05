/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:45:30 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/05 13:21:42 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

# include <testing.h>
# include <stdio.h>

int	node_exec(t_executor *exec)
{
	if (!exec->node)
	{
		dprintf(2, "node_exec null\n");	// DEBUG
		return (1);
	}
	if (exec->node->type == _AND || exec->node->type == _OR)
		return (branch_logicaloperator(exec));
	if (exec->node->type == _PIPE)
		return (branch_pipe(exec));
	if (exec->node->type >= _INPUT && exec->node->type <= _APPEND)
		return (branch_redirection(exec));
	else
		return (branch_command(exec));
	dprintf(2, "node_exec not found\n");	// DEBUG
	return (1);
}
