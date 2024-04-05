/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:32:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/05 13:49:08 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <errno.h>

int	retrieve_status(pid_t pid)
{
	int	status;

	pid = waitpid(pid, &status, 0);
	if (pid == -1 && errno != ECHILD)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (1);
}
