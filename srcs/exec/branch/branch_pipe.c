/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/13 18:35:11 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static int	piping(t_executor *exec, int wait, int pipe[2])
{
	int	error;

	// dprintf(2, "piping\n");	// DEBUG
	// dprintf(2, "pipe[%d]\n", wait);	// DEBUG
	close(pipe[wait]);	// PROTECT
	// dprintf(2, "close(%d) = %d\n", pipe[!wait], close(pipe[!wait]));	// DEBUG
	// dprintf(2, "dup2(%d, %d)\n", pipe[!wait], !wait);	// DEBUG
	// error = dup2(pipe[!wait], !wait);
	if (wait)
		error = ft_vector_add(&exec->outfd, &pipe[STDOUT_FILENO]);	// PROTECT
	else
		error = ft_vector_add(&exec->infd, &pipe[STDIN_FILENO]);	// PROTECT
	close(pipe[!wait]);	// PROTECT
	// error = -1;	// DEBUG
	if (error == -1)
	{
		// dprintf(2, "piping failed\n");	// DEBUG
		close(0);
		close(1);
	}
	return (error);
}

static int	pipe_fork(t_executor *exec, t_astnode *node, int wait, int pipe[2])
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (piping(exec, wait, pipe) == -1)
		{
			free_ast(exec->root);
			// dprintf(2, "end of pipe_fork\n");	// DEBUG
			exit(1);
		}
		exec->node = node;
		ret = node_exec(exec);
		close(0);
		close(1);
		free_ast(exec->root);
		close_fds(exec);
		ft_vector_free(exec->env);
		// dprintf(2, "end of pipe_fork\n");	// DEBUG
		exit(ret);
		// exit(node_exec(exec));
	}
	if (!wait)
	{
		exec->pid = pid;
		return (0);
	}
	close(pipe[0]);
	close(pipe[1]);
	// dprintf(2, "waitpid right\n");	// DEBUG
	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	branch_pipe(t_executor *exec)
{
	t_astnode	*node;
	int			ret;
	int			pipefd[2];

	// dprintf(2, "pipe\n");	// DEBUG
	if (pipe(pipefd) == -1)
		return (1);
	node = exec->node;
	// dprintf(2, "pipe left\n");	// DEBUG
	if (pipe_fork(exec, node->left, 0, pipefd))
		return (1);
	// dprintf(2, "pipe right\n");	// DEBUG
	ret = pipe_fork(exec, node->right, 1, pipefd);
	// close(pipefd[0]);
	// close(pipefd[1]);
	// dprintf(2, "waitpid left\n");	// DEBUG
	if (waitpid(exec->pid, NULL, 0) == -1)
		return (1);
	return (ret);
}
