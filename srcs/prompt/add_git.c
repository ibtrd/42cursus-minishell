/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_git.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:15:50 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/06 16:14:27 by kchillon         ###   ########lyon.fr   */
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
#include <fcntl.h>

static int	get_git_path(char *cmd, char **cmd_path, char *path)
{
	int	ret;
	if (path)
		path = ft_strdup(path);
	ret = search_path(cmd, cmd_path, path);
	free(path);
	return (ret);
}

static int	execute_git(t_vector *env, int try)
{
	static char	*cmd[3][6] = {{"git", "symbolic-ref", "--short", "HEAD", NULL},
		{"git", "describe", "--tags", "--exact-match", "HEAD", NULL},
		{"git", "rev-parse", "--short", "HEAD", NULL}};
	char	*path;
	char	*cmd_path;
	int		ret;

	if (dup2(open("/dev/null", O_WRONLY), STDERR_FILENO) == -1)
		return (1);
	cmd_path = NULL;
	path = ft_getenv(env, "PATH");
	ret = get_git_path(cmd[try][0], &cmd_path, path)
		&& get_git_path(cmd[try][0], &cmd_path, __DEFAULT_PATH);
	if (ret)
		return (1);
	if(!cmd_path)
		return (1);
	execve(cmd_path, cmd[try], env->ptr);
	free(cmd_path);
	ft_vector_free(env);
	return (1);
}

static int	git_fork(t_vector *env, int *pipefd, int try)
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
		close(pipefd[1]);
		if (status == -1)
			exit(1);
		status = execute_git(env, try);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		exit(status);
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
	int		i;

	ret = 1;
	i = 0;
	while (ret && i < 3)
	{
		if (pipe(pipefd) == -1)
			return (1);
		ret = git_fork(env, pipefd, i);
		if (ret)
			close(pipefd[0]);
		i++;
	}
	*branch = NULL;
	if (!ret)
		ret = get_next_line(pipefd[0], branch);
	close(pipefd[0]);
	return (ret);
}

int	add_git(t_vector *env, char **prompt, void *color_flag)
{
	char	*branch;
	char	*git;
	char	*tmp;

	if (git_branch(env, &branch) || !branch)
		return (1);
	branch[ft_strlen(branch) - 1] = '\0';
	if (color_flag)
		git = ft_sprintf(__GIT_PROMPT, P_BOLD, P_CYAN, branch);
	else
		git = ft_sprintf("[%s]", branch);
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
