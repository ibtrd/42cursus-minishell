/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_logicaloperator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 19:35:27 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_executor.h"
#include "minishell_def.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>


static int	logop_left(t_executor *exec)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		exec->node = exec->node->left;
		exit(node_exec(exec));
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

	node = exec->node;
	ret = logop_left(exec);
	exec->node = node->right;
	if (node->type == _AND && ret == 0)	// invert _AND and _OR
		return (node_exec(exec));
	if (node->type == _OR && ret != 0)
		return (node_exec(exec));
	return (ret);
}
