/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:01:09 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/05 17:21:06 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor.h"
#include "minishelldef.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static int	get_cmd_path(char *cmd, char **cmd_path)
{
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (0);
		// command not found
		return (127);
	}
	path = getenv("PATH");
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
	// command not found
	return (127);
}

// static void	**dup_array(void **src, size_t size)
// {
// 	size_t	i;
// 	void	**dst;

// 	dst = malloc(sizeof(void *) * size);
// 	if (!dst)
// 		return (NULL);
// 	i = 0;
// 	while (i < size)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	return (dst);
// }

static int	execute_command(t_executor *exec)
{
	char	**cmd;
	char	*path;
	int		ret;

	path = NULL;
	cmd = (char **)ft_vector_get(exec->node->args, 0);
	ret = get_cmd_path(cmd[0], &path);
	if (ret)
		return (ret);
	dprintf(2, "execve command\n");	// DEBUG
	execve(path, cmd, exec->env);
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
		dprintf(2, "end of command_fork (fail)\n");	// DEBUG
		exit(ret);
		// exit(execute_command(exec));
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
	dprintf(2, "command\n");	// DEBUG
	return (command_fork(exec));
}
