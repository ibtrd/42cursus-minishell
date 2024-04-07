/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/07 19:46:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "signals.h"

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int	piping(t_executor *exec, int wait, int pipe[2])
{
	int	error;

	close(pipe[wait]);
	if (!wait)
		error = ft_vector_add(&exec->outfd, &pipe[STDOUT_FILENO]);
	else
		error = ft_vector_add(&exec->infd, &pipe[STDIN_FILENO]);
	if (error == -1)
		close(pipe[!wait]);
	return (error);
}

static int	pipe_fork(t_executor *exec, t_astnode *node, int wait, int pipe[2])
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (piping(exec, wait, pipe) == -1)
			exit(exec_cleanup(exec, 1));
		signal_setup_child();
		exec->node = node;
		ret = node_exec(exec);
		exit(exec_cleanup(exec, ret));
	}
	if (!wait)
	{
		exec->pid = pid;
		return (0);
	}
	close(pipe[0]);
	close(pipe[1]);
	return (retrieve_status(pid));
}

int	branch_pipe(t_executor *exec)
{
	t_astnode	*node;
	int			ret;
	int			pipefd[2];

	if (pipe(pipefd) == -1)
		return (1);
	node = exec->node;
	if (pipe_fork(exec, node->left, 0, pipefd))
		return (1);
	ret = pipe_fork(exec, node->right, 1, pipefd);
	if (waitpid(exec->pid, NULL, 0) == -1)
		return (1);
	return (ret);
}
