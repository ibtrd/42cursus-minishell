/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_logicaloperator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/05 14:25:50 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static int	logop_fork(t_executor *exec, t_astnode *node)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		exec->node = node;
		ret = node_exec(exec);
		close(0);
		close(1);
		free_ast(exec->root);
		dprintf(2, "end of logicaloperator_fork\n");	// DEBUG
		exit(ret);
		// exit(node_exec(exec));
	}
	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	branch_logicaloperator(t_executor *exec)
{
	t_astnode	*node;
	int	ret;

	dprintf(2, "logicaloperator\n");	// DEBUG
	node = exec->node;
	ret = logop_fork(exec, node->left);
	if (node->type == _AND && !ret)
		ret = logop_fork(exec, node->right);
	else if (node->type == _OR && ret)
		ret = logop_fork(exec, node->right);
	return (ret);
}
