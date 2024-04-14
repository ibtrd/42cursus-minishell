/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:45:30 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:48:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	node_exec(t_executor *exec)
{
	if (!exec->node)
		return (0);
	if (exec->node->type == _AND || exec->node->type == _OR)
		return (branch_logicaloperator(exec));
	if (exec->node->type == _PIPE)
		return (branch_pipe(exec));
	if (exec->node->type >= _INPUT && exec->node->type <= _APPEND)
		return (branch_redirection(exec));
	else
		return (branch_command(exec));
	return (1);
}
