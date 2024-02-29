/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:58 by kchillon          #+#    #+#             */
/*   Updated: 2024/02/23 18:57:44 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_ast.h"
#include "minishell_executor.h"
#include "minishell_def.h"

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

int	node_exec(t_executor *exec)
{
	if (!exec->node)
		return (1);
	if (exec->node->type == _AND || exec->node->type == _OR)
		return (branch_logicaloperator(exec));
	if (exec->node->type == _PIPE)
		return (branch_pipe(exec));
	if (exec->node->type >= _INPUT && exec->node->type <= _APPEND)
		return (branch_redirection(exec));
	else
		return (branch_command(exec));
	return (1);
}

int	exec_init(t_executor *exec, t_astnode *root, char **env, char *program)
{
	exec->env = env;
	exec->program = program;
	exec->pipe[0] = -1;
	exec->pipe[1] = -1;
	exec->background = 1;
	exec->last_pid = 0;
	exec->last_status = 0;
	exec->node = root;
	exec->in = dup(0);	// PROTECT
	exec->out = dup(1);	// PROTECT
	return (1);
}

int	executor(t_astnode *root, char **env, char *program)
{
	t_executor	exec;

	exec_init(&exec, root, env, program);
	node_exec(&exec);
	return (1);
}

// FORK A CHAQUE NOEUD
