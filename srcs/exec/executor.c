/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/12 19:00:20 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishelldef.h"
#include <unistd.h>

#include <stdio.h>

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
	int	fd;

	exec->env = env;
	exec->pid = 0;
	exec->node = root;
	exec->root = root;
	exec->infd = (t_vector){0};
	exec->outfd= (t_vector){0};
	if (ft_vector_init(&exec->infd, (t_vinfos){sizeof(int), 1, NULL}))
		return (1);
	if (ft_vector_init(&exec->outfd, (t_vinfos){sizeof(int), 1, NULL}))
		return (1);
	fd = dup(STDIN_FILENO);
	if (fd == -1)
		return (1);
	if (ft_vector_add(&exec->infd, &fd))
		return (1);
	fd = dup(STDOUT_FILENO);
	if (fd == -1)
		return (1);
	if (ft_vector_add(&exec->outfd, &fd))
		return (1);
	return (0);
}

int	exec_cleanup(t_executor *exec)
{
	// if (dup2(exec->in, 0))
	// 	return (1);
	// if (dup2(exec->out, 1))
	// 	return (1);
	// close(exec->in);
	// close(exec->out);
	close_fds(exec);
	return (0);
}

int	executor(t_astnode *root, char **env)
{
	t_executor	exec;
	int			ret;

	if (exec_init(&exec, root, env))
	{
		// dprintf(2, "exec_init failed\n");	// DEBUG
		exec_cleanup(&exec);
		return (1);
	}
	ret = node_exec(&exec);
	exec_cleanup(&exec);
	return (ret);
}

// FORK A CHAQUE NOEUD
