/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_git.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:15:50 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/16 18:18:59 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <sys/wait.h>
#include <unistd.h>

static int	git_fork(int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execve("git", "git", "branch", "--show-current", NULL);
		exit(1);
	}
	return (0);
}

int	add_git(t_vector *env, char **prompt)
{
	int	pipefd[2];
	int		ret;

	(void)env;
	(void)prompt;
	if (pipe(pipefd) == -1)
		return (1);
	return (0);
}