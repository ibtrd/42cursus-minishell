/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/15 15:43:47 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"
#include "minishelldef.h"
#include "signals.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

static int	get_cmd_path(char *cmd, char **cmd_path, char *path)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
		{
			*cmd_path = ft_strdup(cmd);
			return (!*cmd_path);
		}
		ft_dprintf(STDERR_FILENO, __ERR, __MINISHELL, cmd, strerror(ENOENT));
		return (127);
	}
	if (!search_path(cmd, cmd_path, path))
		return (0);
	if (path && *path && !*cmd_path)
		ft_dprintf(STDERR_FILENO, __CMD_NOT_FOUND, cmd);
	if (!path || !*path)
		ft_dprintf(STDERR_FILENO, __ERR, __MINISHELL, cmd, strerror(ENOENT));
	return (127);
}

static int	is_dir(char *path)
{
	struct stat	buf;

	if (stat(path, &buf))
	{
		ft_dprintf(STDERR_FILENO, __ERR,
			__MINISHELL, path, strerror(errno));
		free(path);
		return (1);
	}
	if (S_ISDIR(buf.st_mode))
	{
		ft_dprintf(STDERR_FILENO, __ERR, __MINISHELL, path, strerror(EISDIR));
		free(path);
		return (1);
	}
	return (0);
}

static int	execute_command(t_executor *exec)
{
	char	**cmd;
	char	*path;
	char	*cmd_path;
	int		ret;

	ft_vector_free(&exec->infd);
	ft_vector_free(&exec->outfd);
	cmd_path = NULL;
	path = ft_getenv(exec->env, "PATH");
	if (path)
		path = ft_strdup(path);
	cmd = (char **)ft_vector_get(exec->node->args, 0);
	ret = get_cmd_path(cmd[0], &cmd_path, path);
	free(path);
	if (ret)
		return (ret);
	if (is_dir(cmd_path))
		return (126);
	execve(cmd_path, cmd, exec->env->ptr);
	ft_dprintf(STDERR_FILENO, __ERR, __MINISHELL, *cmd, strerror(errno));
	free(cmd_path);
	return (126);
}

static int	command_fork(t_executor *exec)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		exec->is_main = 0;
		signal_setup_child();
		if (apply_redirections(exec))
			exit(exec_cleanup(exec, 1));
		ret = execute_command(exec);
		exec_cleanup(exec, 0);
		exit(ret);
	}
	return (retrieve_status(pid));
}

int	branch_command(t_executor *exec)
{
	int			ret;
	const char	*builtins[] = {
		__ECHO, __CD, __PWD, __EXPORT, __UNSET, __ENV, __EXIT, __HISTORY, NULL
	};

	if (expand_node(exec->node, exec->minishell))
		return (1);
	if (exec->node->args->total == 1)
		return (0);
	ret = ft_str_in_array(*(char **)exec->node->args->ptr, builtins);
	if (ret != -1)
		return (exec_builtins(exec, ret));
	ret = command_fork(exec);
	if (is_signal(ret) && exec->is_main)
	{
		if (g_signal == SIGQUIT)
			printf(__QUIT);
		printf("\n");
	}
	return (ret);
}
