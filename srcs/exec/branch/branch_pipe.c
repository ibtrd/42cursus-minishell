/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/22 18:43:29 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "libft.h"
#include "signals.h"

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# include <stdio.h>

static int	piping(t_executor *exec, int wait, int pipe[2])
{
	int	error;

	close(pipe[wait]);
    error = dup2(pipe[!wait], !wait);
	if (error != -1)
	{
		if (!wait)
			error = ft_vector_add(&exec->outfd, &pipe[STDOUT_FILENO]);
		else
			error = ft_vector_add(&exec->infd, &pipe[STDIN_FILENO]);
	}
	else
        ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
	if (error == -1)
	{
		close(0);
		close(1);
		close(pipe[!wait]);
		exec_cleanup(exec);
	}
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
		ret = 1;
		if (!signal_setup_child())
		{
			if (piping(exec, wait, pipe) == -1)
				exit(1);
			exec->node = node;
			ret = node_exec(exec);
		}
		close(0);
		close(1);
		exec_cleanup(exec);
		exit(ret);
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
