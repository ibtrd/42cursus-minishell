/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/22 19:20:58 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_ast.h"
#include "minishell_executor.h"
#include "minishell_def.h"

int	execute_redirection(t_astnode *root)
{
	(void)root;

	if (root->type == _INPUT)
	{
		// open file
		// dup2(file, 0)
	}
	if (root->type == _OUTPUT)
	{
		// open file
		// dup2(file, 1)
	}
	if (root->type == _APPEND)
	{
		// open file
		// dup2(file, 1)
	}
	return (0);
}

int	what_type(t_executor *exec)
{
	if (!exec->node)
		return (1);
	if (exec->node->type == _AND || exec->node->type == _OR)
		return (execute_logicaloperator(exec));
	if (exec->node->type == _PIPE)
		return (execute_pipe(exec));
	if (exec->node->type >= _INPUT && exec->node->type <= _APPEND)
		return (execute_redirection(exec));
	else
		return (execute_command(exec));
	return (1);
}

int	exec_init(t_executor *exec, t_astnode *root)
{
	exec->in = dup(0);
	exec->out = dup(1);
	exec->pipe[0] = -1;
	exec->pipe[1] = -1;
	exec->background = 1;
	exec->last_pid = 0;
	exec->last_status = 0;
	exec->node = root;
	return (1);
}

int	executor(t_astnode *root)
{
	t_executor	exec;

	exec_init(&exec, root);
	what_type(&exec);
	return (1);
}
