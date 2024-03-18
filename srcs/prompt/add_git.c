/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_git.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:15:50 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/17 18:47:27 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishelldef.h"
#include "env.h"
#include "minishell.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

static int	execute_git(t_vector *env)
{
	static char	*cmd[] = {"git", "branch", "--show-current", NULL};
	char	*path;
	char	*cmd_path;
	int		ret;

	cmd_path = NULL;
	path = ft_strdup(ft_getenv(env, "PATH"));
	if (!path)
		path = ft_strdup(__DEFAULT_PATH);
	ret = search_path(cmd[0], &cmd_path, path);
	free(path);
	if (ret)
		return (ret);
	if(!cmd_path)
		return (1);
	close(2);
	execve(cmd_path, cmd, env->ptr);
	close(1);
	free(cmd_path);
	return (1);
}

static int	git_fork(t_vector *env, int *pipefd)
{
	pid_t	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(pipefd[0]);
		status = dup2(pipefd[1], STDOUT_FILENO);
		// if (status != -1)
		// 	status = dup2(pipefd[1], STDERR_FILENO);
		close(pipefd[1]);
		if (status == -1)
			exit(1);
		exit(execute_git(env));
	}
	close(pipefd[1]);
	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

static int	git_branch(t_vector *env, char **branch)
{
	int	pipefd[2];
	int		ret;

	if (pipe(pipefd) == -1)
		return (1);
	ret = git_fork(env, pipefd);
	close(pipefd[1]);
	if (!ret)
		ret = get_next_line(pipefd[0], branch);
	close(pipefd[0]);
	return (ret);
}

int	add_git(t_vector *env, char **prompt)
{
	char	*branch;
	char	*git;
	char	*tmp;

	branch = NULL;
	if (git_branch(env, &branch) || !branch)
		return (1);
	branch[ft_strlen(branch) - 1] = '\0';
	git = ft_sprintf(__GIT_PROMPT, branch);
	if (!git)
	{
		free(branch);
		return (1);
	}
	tmp = ft_strjoin2(*prompt, git, " ");
	free(git);
	free(branch);
	if (tmp)
	{
		free(*prompt);
		*prompt = tmp;
	}
	return (!tmp);
}
