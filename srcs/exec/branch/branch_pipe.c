/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:08:56 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/16 16:38:35 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include "libft.h"

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
		{
			// dprintf(2, "wait = 0\tfd = %d\n", pipe[STDOUT_FILENO]);	// DEBUG
			error = ft_vector_add(&exec->outfd, &pipe[STDOUT_FILENO]);
		}
		else
		{
			// dprintf(2, "wait = 1\tfd = %d\n", pipe[STDIN_FILENO]);	// DEBUG
			error = ft_vector_add(&exec->infd, &pipe[STDIN_FILENO]);
		}
	}
	else
        ft_dprintf(2, "%s: %s\n", __MINISHELL, strerror(errno));
	// printf_redir(exec);	// DEBUG
	// usleep(100000);	// DEBUG
	if (error == -1)
	{
		close(0);
		close(1);
		close(pipe[!wait]);
		exec_cleanup(exec);
	}
	// dprintf(2, "error = %d\n", error);	// DEBUG
	return (error);
}

static int	retrieve_status(pid_t pid)
{
	int	status;

	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

static int	pipe_fork(t_executor *exec, t_astnode *node, int wait, int pipe[2])
{
	pid_t	pid;
	int		ret;
	// static int	i = 0;

	// i = (i + 1) % 2;
	// dprintf(2, "%d. cmd = %s\n", i, *(char **)ft_vector_get(node->args, 0));	// DEBUG
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (piping(exec, wait, pipe) == -1)
			exit(1);
		exec->node = node;
		ret = node_exec(exec);
		// usleep(10000);	// DEBUG
		// if (close(0))
		// 	printf("close 0 failed\n");
		close(0);
		close(1);
		// dprintf(2, "cmd = %s\n", *(char **)ft_vector_get(node->args, 0));	// DEBUG
		// if (i)
		// 	dprintf(2, "\n");	// DEBUG
		exec_cleanup(exec);
		// printf_redir(exec);	// DEBUG
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
