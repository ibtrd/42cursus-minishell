/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:45:30 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/20 17:19:52 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "ast.h"
#include "minishell.h"

int	node_exec(t_executor *exec)
{
	if (!exec->node)
		return (0);
	if (expand_node(exec->node, exec->minishell))
		return (1);
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
