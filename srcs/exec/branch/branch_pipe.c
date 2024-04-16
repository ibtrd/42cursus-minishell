/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/16 14:31:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "signals.h"

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

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

static void	pipe_behaviour(t_executor *exec, t_astnode *node, int wait,
	int pipe[2])
{
	int	ret;

	exec->is_main = 0;
	if (piping(exec, wait, pipe) == -1)
		exit(exec_cleanup(exec, 1));
	signal_setup_pipe();
	exec->node = node;
	ret = node_exec(exec);
	exec_cleanup(exec, 0);
	if (is_signal(ret) && ((get_exit_status(ret) == SIGINT)
			|| (get_exit_status(ret) == SIGQUIT)))
	{
		signal_setup_child();
		kill(0, get_exit_status(ret) - 128);
	}
	exit(ret);
}

static int	pipe_fork(t_executor *exec, t_astnode *node, int wait, int pipe[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		pipe_behaviour(exec, node, wait, pipe);
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
	int			got_a_signal;

	if (pipe(pipefd) == -1)
		return (1);
	node = exec->node;
	if (pipe_fork(exec, node->left, 0, pipefd))
		return (1);
	ret = pipe_fork(exec, node->right, 1, pipefd);
	got_a_signal = retrieve_status(exec->pid);
	if ((is_signal(ret) || got_a_signal) && exec->is_main)
		display_signal_msg();
	return (ret);
}
