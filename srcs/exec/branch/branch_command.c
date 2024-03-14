/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 16:52:38 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor.h"
#include "minishelldef.h"
#include "env.h"

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# include <stdio.h>

static int	get_cmd_path(char *cmd, char **cmd_path, char *path)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (0);
		ft_dprintf(2, "%s: %s: %s\n", __MINISHELL, cmd, __CMD_NOT_FOUND);
		return (127);
	}
	if (path)
	{
		*cmd_path = ft_strtok(path, ":");
		while (*cmd_path)
		{
			*cmd_path = ft_strjoin2(*cmd_path, "/", cmd);
			if (!*cmd_path)
				return (1);
			if (access(*cmd_path, F_OK) == 0)
				return (0);
			free(*cmd_path);
			*cmd_path = ft_strtok(NULL, ":");
		}
	}
	ft_dprintf(2, "%s: %s: %s\n", __MINISHELL, cmd, __CMD_NOT_FOUND);
	return (127);
}

static int	dup_fd(t_executor *exec)
{
	int	ret;

	ret = dup2(*(int *)ft_vector_get(&exec->infd, exec->infd.total - 1), STDIN_FILENO);
	if (ret != -1)
		ret = dup2(*(int *)ft_vector_get(&exec->outfd, exec->outfd.total - 1), STDOUT_FILENO);
	ft_vector_free(&exec->infd);
	ft_vector_free(&exec->outfd);
	return (ret == -1);
}

static int	execute_command(t_executor *exec)
{
	char	**cmd;
	char	*path;
	int		ret;

	if (dup_fd(exec))
		return (1);
	path = NULL;
	cmd = (char **)ft_vector_get(exec->node->args, 0);
	ret = get_cmd_path(cmd[0], &path, ft_getenv(exec->env, "PATH"));
	if (ret)
		return (ret);
	execve(path, cmd, exec->env->ptr);
	dprintf(2, "apres commande\n");	// DEBUG
	free(path);
	return (1);
}

static int	command_fork(t_executor *exec)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		ret = execute_command(exec);
		close(0);
		close(1);
		free_ast(exec->root);
		ft_vector_free(exec->env);
		exit(ret);
	}
	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	branch_command(t_executor *exec)
{
	int			ret;
	const char	*builtins[] = {"echo", "cd", "pwd", "export", "unset", "env",
								"exit", NULL};

	ret = ft_str_in_array(*(char **)ft_vector_get(exec->node->args, 0), builtins);
	if (ret != -1)
		return (exec_builtins(exec, ret));
	return (command_fork(exec));
}
