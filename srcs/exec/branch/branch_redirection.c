/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/08 03:11:02 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
# include <testing.h>

static int	open_redirect(t_executor *exec)
{
	static const t_open_redirect	open_redirect[4] = {open_input, \
														open_output, \
														open_append, \
														open_input};

	dprintf(2, "open_redirect\n");	// DEBUG
	return (open_redirect[exec->node->type - _INPUT](exec));
}

static int	redirect_fork(t_executor *exec, t_astnode *node)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (open_redirect(exec))
		{
			dprintf(2, "open_redirect failed\n");	// DEBUG
			close(0);
			close(1);
			free_ast(exec->root);
			dprintf(2, "end of redirect_fork\n");	// DEBUG
			exit(1);
		}
		dprintf(2, "open_redirect success\n");	// DEBUG
		exec->node = node;
		ret = node_exec(exec);
		// exit(dprintf(2, "node_exec: %d\n", node_exec(exec)));
		close(0);
		close(1);
		free_ast(exec->root);
		dprintf(2, "end of redirect_fork\n");	// DEBUG
		exit(ret);
	}
	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	branch_redirection(t_executor *exec)
{
	dprintf(2, "redirection\n");	// DEBUG
	dprint_ast(2, exec->node, NULL);	// DEBUG
	return (redirect_fork(exec, exec->node->right));
}
