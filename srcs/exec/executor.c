/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/05 14:24:29 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <unistd.h>

// int	pipe_left(t_executor *exec, int pipefd[2])
// {
// 	exec->last_pid = fork();
// 	if (exec->last_pid == -1)
// 		return (1);
// 	if (exec->last_pid == 0)
// 	{
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		close(pipefd[0]);
// 		node_exec(exec);
// 		exit(exec->last_status);
// 	}
// 	close(pipefd[0]);
// 	return (0);
// }

// int	branch_pipe(t_executor *exec)
// {
// 	int	pipefd[2];
// 	int	ret;

// 	if (pipe(pipefd) == -1)
// 		return (1);

// 	pipe_left(exec, pipefd);
// // left
// 	dup2(pipefd[1], 1);
// 	close(pipefd[1]);
// 	close(pipefd[0]);

// // right
// 	dup2(pipefd[0], 0);
	
// 	return (ret);

// }

// int	branch_pipe(t_executor *exec)
// {
// 	int	pipefd[2];
// 	int	ret;

// 	if (pipe(pipefd) == -1)
// 		return (1);
// 	exec->pipe[1] = pipefd[1];
// 	exec->last_pid = fork();
// 	if (exec->last_pid == -1)
// 		return (1);
// 	if (exec->last_pid == 0)
// 	{
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		close(pipefd[0]);
// 		node_exec(exec);
// 		exit(exec->last_status);
// 	}
// 	close(pipefd[0]);
// 	ret = exec->last_status;
// 	exec->pipe[0] = pipefd[1];
// 	exec->node = exec->node->right;
// 	return (ret);

// }

int	exec_init(t_executor *exec, t_astnode *root, char **env)
{
	exec->env = env;
	exec->pipe[0] = -1;
	exec->pipe[1] = -1;
	exec->background = 1;
	exec->pid = 0;
	exec->last_status = 0;
	exec->node = root;
	exec->root = root;
	// exec->in = dup(0);	// PROTECT
	// exec->out = dup(1);	// PROTECT
	return (1);
}

int	exec_cleanup(t_executor *exec)
{
	if (exec->pipe[0] != -1)
		close(exec->pipe[0]);
	if (exec->pipe[1] != -1)
		close(exec->pipe[1]);
	if (dup2(exec->in, 0))
		return (1);
	if (dup2(exec->out, 1))
		return (1);
	close(exec->in);
	close(exec->out);
	return (0);
}

int	executor(t_astnode *root, char **env)
{
	t_executor	exec;

	exec_init(&exec, root, env);
	return (node_exec(&exec));
}

// FORK A CHAQUE NOEUD
